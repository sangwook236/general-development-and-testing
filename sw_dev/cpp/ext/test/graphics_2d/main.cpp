//#include "stdafx.h"
#if defined(_WIN64) || defined(WIN64) || defined(_WIN32) || defined(WIN32)
#include <vld/vld.h>
#endif
#include <iostream>
#include <stdexcept>
#include <cstdlib>


int main(int argc, char *argv[])
{
	int cairo_main(int argc, char *argv[]);
	int gd_main(int argc, char *argv[]);
	int magickwand_main(int argc, char *argv[]);
	int devil_main(int argc, char *argv[]);

	int retval = EXIT_SUCCESS;
	try
	{
		std::cout << "Cairo library -------------------------------------------------------" << std::endl;
		retval = cairo_main(argc, argv);
		std::cout << "\nGD Graphics Library -------------------------------------------------" << std::endl;
		//retval = gd_main(argc, argv);
		std::cout << "\nGD MagickWand Library -----------------------------------------------" << std::endl;
		//retval = magickwand_main(argc, argv);

		std::cout << "\nDeveloper's Image Library (DevIL) -----------------------------------" << std::endl;
		//retval = devil_main(argc, argv);
	}
    catch (const std::bad_alloc &e)
	{
		std::cout << "std::bad_alloc caught: " << e.what() << std::endl;
		retval = EXIT_FAILURE;
	}
	catch (const std::exception &e)
	{
		std::cout << "std::exception caught: " << e.what() << std::endl;
		retval = EXIT_FAILURE;
	}
	catch (...)
	{
		std::cout << "Unknown exception caught" << std::endl;
		retval = EXIT_FAILURE;
	}

	std::cout << "Press any key to exit ..." << std::endl;
	std::cin.get();

	return retval;
}
