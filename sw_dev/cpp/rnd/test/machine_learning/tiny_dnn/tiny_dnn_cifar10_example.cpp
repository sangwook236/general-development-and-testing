#include <opencv2/opencv.hpp>
#include <tiny_dnn/tiny_dnn.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


namespace local {
namespace {

template <typename N>
void construct_net(N& nn)
{
    typedef tiny_dnn::convolutional_layer<tiny_dnn::activation::identity> conv;
    typedef tiny_dnn::max_pooling_layer<tiny_dnn::activation::relu> pool;

    const int n_fmaps = 32;  // Number of feature maps for upper layer.
    const int n_fmaps2 = 64;  // Number of feature maps for lower layer.
    const int n_fc = 64;  // Number of hidden units in fully-connected layer.

    nn << conv(32, 32, 5, 3, n_fmaps, tiny_dnn::core::padding::same)
        << pool(32, 32, n_fmaps, 2)
        << conv(16, 16, 5, n_fmaps, n_fmaps, tiny_dnn::core::padding::same)
        << pool(16, 16, n_fmaps, 2)
        << conv(8, 8, 5, n_fmaps, n_fmaps2, tiny_dnn::core::padding::same)
        << pool(8, 8, n_fmaps2, 2)
        << tiny_dnn::fully_connected_layer<tiny_dnn::activation::identity>(4 * 4 * n_fmaps2, n_fc)
        << tiny_dnn::fully_connected_layer<tiny_dnn::activation::softmax>(n_fc, 10);
}

// Rescale output to 0-100.
template <typename Activation>
double rescale(double x)
{
	Activation a;
	return 100.0 * (x - a.scale().first) / (a.scale().second - a.scale().first);
}

void convert_image(const std::string& imagefilename, double minv, double maxv, int w, int h, tiny_dnn::vec_t& data)
{
	cv::Mat img = cv::imread(imagefilename);
	if (nullptr == img.data) return;  // Cannot open, or it's not an image
	cv::Mat resized;
	cv::resize(img, resized, cv::Size(w, h), .0, .0);
	data.resize(w * h * resized.channels(), (float)minv);
	for (int c = 0; c < resized.channels(); ++c)
		for (int y = 0; y < resized.rows; ++y)
			for (int x = 0; x < resized.cols; ++x)
				data[c * w * h + y * w + x] = resized.data[y * resized.step + x * resized.step + c];
}

void train_cifar10(const std::string& data_dir_path, const double learning_rate, std::ostream& log)
{
	tiny_dnn::network<tiny_dnn::sequential> nn;
	tiny_dnn::adam optimizer;

	construct_net(nn);

	log << "Learning rate:" << learning_rate << std::endl;

	std::cout << "Load models..." << std::endl;

	// Load cifar dataset.
	std::vector<tiny_dnn::label_t> train_labels, test_labels;
	std::vector<tiny_dnn::vec_t> train_images, test_images;

	for (int i = 1; i <= 5; ++i)
		tiny_dnn::parse_cifar10(data_dir_path + "/data_batch_" + std::to_string(i) + ".bin", &train_images, &train_labels, -1.0, 1.0, 0, 0);

	tiny_dnn::parse_cifar10(data_dir_path + "/test_batch.bin", &test_images, &test_labels, -1.0, 1.0, 0, 0);

	std::cout << "Start learning" << std::endl;

	tiny_dnn::progress_display disp((unsigned long)train_images.size());
	tiny_dnn::timer t;
	const int n_minibatch = 10;     ///< minibatch size
	const int n_train_epochs = 30;  ///< training duration

	optimizer.alpha *= static_cast<tiny_dnn::float_t>(std::sqrt(n_minibatch) * learning_rate);

	// Create callback.
	auto on_enumerate_epoch = [&]()
	{
		std::cout << t.elapsed() << "s elapsed." << std::endl;
		tiny_dnn::result res = nn.test(test_images, test_labels);
		log << res.num_success << "/" << res.num_total << std::endl;

		disp.restart((unsigned long)train_images.size());
		t.restart();
	};

	auto on_enumerate_minibatch = [&]()
	{
		disp += n_minibatch;
	};

	// Training.
	nn.train<tiny_dnn::cross_entropy>(optimizer, train_images, train_labels, n_minibatch, n_train_epochs, on_enumerate_minibatch, on_enumerate_epoch);

	std::cout << "End training." << std::endl;

	//
	std::cout << "Start testing." << std::endl;

	// Test and show results.
	nn.test(test_images, test_labels).print_detail(std::cout);

	std::cout << "End testing." << std::endl;

	// Save networks.
#if 1
	std::ofstream ofs("./data/machine_learning/tiny_dnn/cifar-weights");
	ofs << nn;
#else
	nn.save("./data/machine_learning/tiny_dnn/cifar-weights");
#endif
}

void recognize(const std::string& dictionary, const std::string& filename)
{
	tiny_dnn::network<tiny_dnn::sequential> nn;

	construct_net(nn);

	// Load nets.
#if 1
	std::ifstream ifs(dictionary.c_str());
	ifs >> nn;
#else
	nn.load(dictionary);
#endif

	// Convert imagefile to vec_t.
	tiny_dnn::vec_t data;
	convert_image(filename, -1.0, 1.0, 32, 32, data);

	// Recognize.
	auto res = nn.predict(data);
	std::vector<std::pair<double, int> > scores;

	// Sort & print top-3.
	for (int i = 0; i < 10; i++)
		scores.emplace_back(rescale<tiny_dnn::tan_h>(res[i]), i);

	std::sort(scores.begin(), scores.end(), std::greater<std::pair<double, int>>());

	for (int i = 0; i < 3; i++)
		std::cout << scores[i].second << "," << scores[i].first << std::endl;
}

}  // namespace local
}  // unnamed namespace

namespace my_tiny_dnn {

// REF [file] >> ${TINY_DNN_HOME}/examples/cifar10/train.cpp
void cifar10_train_example()
{
	// REF [site] >> http://www.cs.toronto.edu/~kriz/cifar.html
	const std::string path_to_data("./data/machine_learning/cifar10");
	const double learning_rate = 0.01;

	local::train_cifar10(path_to_data, learning_rate, std::cout);
}

// REF [file] >> ${TINY_DNN_HOME}/examples/cifar10/test.cpp
void cifar10_test_example()
{
	const std::string image_file("./data/machine_learning/cifar10/???.???");
	local::recognize("./data/machine_learning/tiny_dnn/cifar-weights", image_file);
}

}  // namespace my_tiny_dnn
