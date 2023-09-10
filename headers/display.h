#ifndef HEADERS_DISPLAY_H
#define HEADERS_DISPALY_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t display(char *str);
size_t countArgs(char *str);
size_t out(char *str);
void errorFormat(void);
char **allocateMemory(char *str, size_t size);
void freeAll(void);
size_t checkSepa(char *str);

typedef struct display_s
{
	char *string;
	char **args;
} display_t;

extern display_t disp;


#endif
