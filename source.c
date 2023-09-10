#include "headers/display.h"
display_t disp;

/**
 * display - dispalys inputs
 * @str: the main string includs arguments
 * Return: 0 if success otherways 1
*/
size_t display(char *str)
{
	if (!str || *str == '\0')
		return (out("\n"));
	disp.args = allocateMemory(str, countArgs(str));
	int i = 0;

	while (disp.args[i])
	{
		if (!checkSepa(disp.args[i]))
			errorFormat();
		i++;
	}
	i = 0;
	parammiter();
	/* setParammiter(); */
	while (disp.para && disp.para[i])
	{
		out(disp.para[i]);
		out("\n");
		i++;
	}
	i = 1;
	while (disp.args[i])
	{
		out(disp.args[i]);
		out(" ");
		i++;
	}
	out("\n");
	freeAll();
	return (0);
}
