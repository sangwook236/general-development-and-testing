#include <stdlib.h>


int main(void)
{
	int uart_main();
	int spi_main();
	int i2c_main();

	// Important !!!
	// In order to make use of functions, do set "Properties -> Build Action" to "None -> Compile".

	int retval = EXIT_SUCCESS;
	{
		retval = uart_main();  // not yet implemented.
		//retval = spi_main();  // not yet implemented.
		//retval = i2c_main();  // not yet implemented.
	}

	return retval;
}