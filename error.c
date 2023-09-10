#include "headers/display.h"

/**
 * errorFormat - exit with error
*/
void errorFormat(void)
{
	write(STDERR_FILENO, "!!!!!!!!!!!!!!!!!!!!!!!!!!!\nuncorrect format\n", 45);
	freeAll();
	exit(1);
}
