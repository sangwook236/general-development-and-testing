#include <iostream>


namespace {
namespace local {

}  // namespace local
}  // unnamed namespace

namespace my_plplot {

void example_x01(int argc, const char **argv);
void example_x21(int argc, const char **argv);

}  // namespace my_plplot

int plplot_main(int argc, char *argv[])
{
	// caution: for execution, driver files have to be loaded.

	// examples
	//my_plplot::example_x01(argc, (const char **)argv);
	my_plplot::example_x21(argc, (const char **)argv);

	return 0;
}
