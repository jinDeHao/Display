#include "headers/display.h"

/**
 * countArgs - count number of argmant
 * @str: the string to count the argument for
 * Return: number of args
*/

size_t countArgs(char *str)
{
	size_t args = 1;

	while (*str)
	{
		args = *str == ',' && (*(str + 1) == '{'
		|| (*(str + 1) == ' ' && *(str + 2) == '{')) ? args + 1 : args;

		str++;
	}
	return (args);
}

/**
 * allocateMemory - allocate and set argument
 * @str: string to allocate for
 * @numArgs: number of arguments
 * Return: arguments array
*/
char **allocateMemory(char *str, size_t numArgs)
{
	char **args = malloc((numArgs + 1) * sizeof(char *));
	char *tok, *del = "{}";
	int i = 0, m = 0;

	disp.string = strdup(str);
	tok = strtok(disp.string, del);
	while (tok)
	{
		if (!(m % 2))
		{
			args[i] = strdup(tok);
			i++;
		}
		tok = strtok(NULL, del);
		m++;
	}
	args[i] = NULL;
	return (args);
}


/**
 * checkSepa - chack for bad format
 * @str: str to check
 * Return: 0 if bad and 1 if good
*/
size_t checkSepa(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * freeAll - free all allocated memory
*/
void freeAll(void)
{
	int i = 0;

	if (disp.args)
	{
		while (disp.args[i])
		{
			free(disp.args[i]);
			i++;
		}
		free(disp.args[i]);
		free(disp.args);
	}
	if (disp.string)
		free(disp.string);
}
