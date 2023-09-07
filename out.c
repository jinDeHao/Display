#include "headers/display.h"
/**
 * out - makes write easy to use
 * @str: the string to write
 * Return: what write returns
 */
size_t out(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}