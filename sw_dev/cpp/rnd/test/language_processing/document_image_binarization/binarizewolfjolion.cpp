/**************************************************************
 * Binarization with several methods
 * (0) Niblacks method
 * (1) Sauvola & Co.
 *     ICDAR 1997, pp 147-152
 * (2) by myself - Christian Wolf
 *     Research notebook 19.4.2001, page 129
 * (3) by myself - Christian Wolf
 *     20.4.2007
 *
 * See also:
 * Research notebook 24.4.2001, page 132 (Calculation of s)
 **************************************************************/

#include <opencv2/opencv.hpp>
//#include <stdio.h>
//#include <unistd.h>
//#include <getopt.h>
#include <iostream>
//#include <cv.h>
//#include <highgui.h>

//using namespace std;
//using namespace cv;

enum NiblackVersion 
{
	NIBLACK=0,
    SAUVOLA,
    WOLFJOLION,
};

#define BINARIZEWOLF_VERSION	"2.4 (August 1st, 2014)"

#define uget(x,y)    at<unsigned char>(y,x)
#define uset(x,y,v)  at<unsigned char>(y,x)=v;
#define fget(x,y)    at<float>(y,x)
#define fset(x,y,v)  at<float>(y,x)=v;

/**********************************************************
 * Usage
 **********************************************************/
/*
static void usage (char *com) {
	std::cerr << "usage: " << com << " [ -x <winx> -y <winy> -k <parameter> ] [ version ] <inputimage> <outputimage>\n\n"
		 << "version: n   Niblack (1986)         needs white text on black background\n"
		 << "         s   Sauvola et al. (1997)  needs black text on white background\n"
		 << "         w   Wolf et al. (2001)     needs black text on white background\n"
		 << "\n"
		 << "Default version: w (Wolf et al. 2001)\n"
		 << "\n"
		 << "example:\n"
		 << "       " << com << " w in.pgm out.pgm\n"
		 << "       " << com << " in.pgm out.pgm\n"
		 << "       " << com << " s -x 50 -y 50 -k 0.6 in.pgm out.pgm\n";
}
*/

// *************************************************************
// glide a window across the image and
// create two maps: mean and standard deviation.
//
// Version patched by Thibault Yohan (using opencv integral images)
// *************************************************************


double calcLocalStats (cv::Mat &im, cv::Mat &map_m, cv::Mat &map_s, int winx, int winy) {    
    cv::Mat im_sum, im_sum_sq;
    cv::integral(im,im_sum,im_sum_sq,CV_64F);

	double m,s,max_s,sum,sum_sq;	
	int wxh	= winx/2;
	int wyh	= winy/2;
	int x_firstth= wxh;
	int y_lastth = im.rows-wyh-1;
	int y_firstth= wyh;
	double winarea = winx*winy;

	max_s = 0;
	for	(int j = y_firstth ; j<=y_lastth; j++){   
		sum = sum_sq = 0;

        sum = im_sum.at<double>(j-wyh+winy,winx) - im_sum.at<double>(j-wyh,winx) - im_sum.at<double>(j-wyh+winy,0) + im_sum.at<double>(j-wyh,0);
        sum_sq = im_sum_sq.at<double>(j-wyh+winy,winx) - im_sum_sq.at<double>(j-wyh,winx) - im_sum_sq.at<double>(j-wyh+winy,0) + im_sum_sq.at<double>(j-wyh,0);

		m  = sum / winarea;
		s  = sqrt ((sum_sq - m*sum)/winarea);
		if (s > max_s) max_s = s;

		map_m.fset(x_firstth, j, m);
		map_s.fset(x_firstth, j, s);

		// Shift the window, add and remove	new/old values to the histogram
		for	(int i=1 ; i <= im.cols-winx; i++) {

			// Remove the left old column and add the right new column
			sum -= im_sum.at<double>(j-wyh+winy,i) - im_sum.at<double>(j-wyh,i) - im_sum.at<double>(j-wyh+winy,i-1) + im_sum.at<double>(j-wyh,i-1);
			sum += im_sum.at<double>(j-wyh+winy,i+winx) - im_sum.at<double>(j-wyh,i+winx) - im_sum.at<double>(j-wyh+winy,i+winx-1) + im_sum.at<double>(j-wyh,i+winx-1);

			sum_sq -= im_sum_sq.at<double>(j-wyh+winy,i) - im_sum_sq.at<double>(j-wyh,i) - im_sum_sq.at<double>(j-wyh+winy,i-1) + im_sum_sq.at<double>(j-wyh,i-1);
			sum_sq += im_sum_sq.at<double>(j-wyh+winy,i+winx) - im_sum_sq.at<double>(j-wyh,i+winx) - im_sum_sq.at<double>(j-wyh+winy,i+winx-1) + im_sum_sq.at<double>(j-wyh,i+winx-1);

			m  = sum / winarea;
			s  = sqrt ((sum_sq - m*sum)/winarea);
			if (s > max_s) max_s = s;

			map_m.fset(i+wxh, j, m);
			map_s.fset(i+wxh, j, s);
		}
	}

	return max_s;
}



/**********************************************************
 * The binarization routine
 **********************************************************/


void NiblackSauvolaWolfJolion (cv::Mat im, cv::Mat output, NiblackVersion version,
	int winx, int winy, double k, double dR) {

	
	double m, s, max_s;
	double th=0;
	double min_I, max_I;
	int wxh	= winx/2;
	int wyh	= winy/2;
	int x_firstth= wxh;
	int x_lastth = im.cols-wxh-1;
	int y_lastth = im.rows-wyh-1;
	int y_firstth= wyh;
	//int mx, my;

	// Create local statistics and store them in a double matrices
	cv::Mat map_m = cv::Mat::zeros (im.rows, im.cols, CV_32F);
	cv::Mat map_s = cv::Mat::zeros (im.rows, im.cols, CV_32F);
	max_s = calcLocalStats (im, map_m, map_s, winx, winy);
	
	cv::minMaxLoc(im, &min_I, &max_I);
			
	cv::Mat thsurf (im.rows, im.cols, CV_32F);
			
	// Create the threshold surface, including border processing
	// ----------------------------------------------------

	for	(int j = y_firstth ; j<=y_lastth; j++) {

		// NORMAL, NON-BORDER AREA IN THE MIDDLE OF THE WINDOW:
		for	(int i=0 ; i <= im.cols-winx; i++) {

			m  = map_m.fget(i+wxh, j);
    		s  = map_s.fget(i+wxh, j);

    		// Calculate the threshold
    		switch (version) {

    			case NIBLACK:
    				th = m + k*s;
    				break;

    			case SAUVOLA:
	    			th = m * (1 + k*(s/dR-1));
	    			break;

    			case WOLFJOLION:
    				th = m + k * (s/max_s-1) * (m-min_I);
    				break;
    				
    			default:
    				std::cerr << "Unknown threshold type in ImageThresholder::surfaceNiblackImproved()\n";
    				exit (1);
    		}
    		
    		thsurf.fset(i+wxh,j,th);

    		if (i==0) {
        		// LEFT BORDER
        		for (int i=0; i<=x_firstth; ++i)
                	thsurf.fset(i,j,th);

        		// LEFT-UPPER CORNER
        		if (j==y_firstth)
        			for (int u=0; u<y_firstth; ++u)
        			for (int i=0; i<=x_firstth; ++i)
        				thsurf.fset(i,u,th);

        		// LEFT-LOWER CORNER
        		if (j==y_lastth)
        			for (int u=y_lastth+1; u<im.rows; ++u)
        			for (int i=0; i<=x_firstth; ++i)
        				thsurf.fset(i,u,th);
    		}

			// UPPER BORDER
			if (j==y_firstth)
				for (int u=0; u<y_firstth; ++u)
					thsurf.fset(i+wxh,u,th);

			// LOWER BORDER
			if (j==y_lastth)
				for (int u=y_lastth+1; u<im.rows; ++u)
					thsurf.fset(i+wxh,u,th);
		}

		// RIGHT BORDER
		for (int i=x_lastth; i<im.cols; ++i)
        	thsurf.fset(i,j,th);

  		// RIGHT-UPPER CORNER
		if (j==y_firstth)
			for (int u=0; u<y_firstth; ++u)
			for (int i=x_lastth; i<im.cols; ++i)
				thsurf.fset(i,u,th);

		// RIGHT-LOWER CORNER
		if (j==y_lastth)
			for (int u=y_lastth+1; u<im.rows; ++u)
			for (int i=x_lastth; i<im.cols; ++i)
				thsurf.fset(i,u,th);
	}
	std::cerr << "surface created" << std::endl;
	
	
	for	(int y=0; y<im.rows; ++y) 
	for	(int x=0; x<im.cols; ++x) 
	{
    	if (im.uget(x,y) >= thsurf.fget(x,y))
    	{
    		output.uset(x,y,255);
    	}
    	else
    	{
    	    output.uset(x,y,0);
    	}
    }
}

/**********************************************************
 * The main function
 **********************************************************/
/*
int main (int argc, char **argv) 
{
	char version;
	int c;
	int winx=0, winy=0;
	float optK=0.5;
	bool didSpecifyK=false;
	NiblackVersion versionCode;	
	char *inputname, *outputname, *versionstring;	
	
	std::cerr << "===========================================================\n"
	     << "Christian Wolf, LIRIS Laboratory, Lyon, France.\n"
		 << "christian.wolf@liris.cnrs.fr\n"
		 << "Version " << BINARIZEWOLF_VERSION << std::endl
		 << "===========================================================\n";

	// Argument processing
	while ((c =	getopt (argc, argv,	"x:y:k:")) != EOF) {

		switch (c) {

			case 'x':
				winx = atof(optarg);
				break;

			case 'y':
				winy = atof(optarg);
				break;

			case 'k':
				optK = atof(optarg);
				didSpecifyK = true;
				break;

			case '?':
				usage (*argv);
				std::cerr << "\nProblem parsing the options!\n\n";
				exit (1);
		}
	}	

	switch(argc-optind)
	{
		case 3:
			versionstring=argv[optind];
			inputname=argv[optind+1];
			outputname=argv[optind+2];
			break;
		
		case 2:
			versionstring=(char *) "w";
			inputname=argv[optind];
			outputname=argv[optind+1];
			break;
			
		default:
			usage (*argv);
			exit (1);
	}
	
	std::cerr << "Adaptive binarization\n"
		 << "Threshold calculation: ";
	
	// Determine the method
	version = versionstring[0];
	switch (version)
	{
		case 'n':
			versionCode = NIBLACK;
			std::cerr << "Niblack (1986)\n";
			break;
	
		case 's':
			versionCode = SAUVOLA;
			std::cerr << "Sauvola et al. (1997)\n";
			break;
			
		case 'w':
			versionCode = WOLFJOLION;
			std::cerr << "Wolf and Jolion (2001)\n";
			break;
				
		default:
			usage (*argv);		
			std::cerr  << "\nInvalid version: '" << version << "'!";			
	}
	
	
	std::cerr << "parameter k=" << optK << std::endl;
	
	if (!didSpecifyK)
		std::cerr << "Setting k to default value " << optK << std::endl;

	
    // Load the image in grayscale mode
    cv::Mat input = cv::imread(inputname, cv::IMREAD_GRAYSCALE);
    
    
    if ((input.rows<=0) || (input.cols<=0)) {
        std::cerr << "*** ERROR: Couldn't read input image " << inputname << std::endl;
        exit(1);
    }
      

    // Treat the window size
    if (winx==0||winy==0) {
        std::cerr << "Input size: " << input.cols << "x" << input.rows << std::endl;
        winy = (int) (2.0 * input.rows-1)/3;
        winx = (int) input.cols-1 < winy ? input.cols-1 : winy;
        // if the window is too big, than we asume that the image
        // is not a single text box, but a document page: set
        // the window size to a fixed constant.
        if (winx > 100)
            winx = winy = 40;
        std::cerr << "Setting window size to [" << winx
            << "," << winy << "].\n";
    }
    
    // Threshold
    cv::Mat output (input.rows, input.cols, CV_8U);
    NiblackSauvolaWolfJolion (input, output, versionCode, winx, winy, optK, 128);

    // Write the tresholded file
    std::cerr << "Writing binarized image to file '" << outputname << "'.\n";
    cv::imwrite (outputname, output);	
        
    return 0;    
}
*/
