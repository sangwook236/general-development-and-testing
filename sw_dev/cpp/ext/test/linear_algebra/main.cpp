#if defined(WIN32)
#include <vld/vld.h>
#endif
#include <iostream>
#include <stdexcept>
#include <cstdlib>


int main(int argc, char* argv[])
{
	int lapack_main(int argc, char* argv[]);
	int atlas_main(int argc, char* argv[]);
	int eigen_main(int argc, char* argv[]);
	int armadillo_main(int argc, char* argv[]);
	int cvm_main(int argc, char* argv[]);
	int mtl_main(int argc, char* argv[]);

	int retval = EXIT_SUCCESS;
	try
	{
		retval = lapack_main(argc, argv);
		
		retval = atlas_main(argc, argv);
		retval = eigen_main(argc, argv);
		retval = armadillo_main(argc, argv);
		
		retval = cvm_main(argc, argv);

		//retval = mtl_main(argc, argv);  // not yet implemented
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
		std::cout << "unknown exception caught" << std::endl;
		retval = EXIT_FAILURE;
	}

	std::cout << "press any key to exit ..." << std::endl;
	std::cin.get();

	return retval;
}