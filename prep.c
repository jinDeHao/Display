#include "headers/display.h"
/**
 * countArgs - count number of argmant
 * @str: the string to count the argument for
 * Return: number of args
*/

size_t countArgs(char *str)
{
	size_t args = 1;
	while (str)
	{
		args = *str == ',' && (*(str + 1) == '"'
		|| (*(str + 1) == ' ' && *(str + 2) == '"'))? args + 1: args;
		str++;
	}
	return (args);
}