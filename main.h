#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);

int _strlen(const char *str);
int print(char *str);
int print_char(va_list);
int print_str(va_list);
int print_int(va_list);
int print_percentage(va_list);
int manipulator(const char *str, va_list ap);
int perman(const char *str, va_list ap, int *i);

/**
 * struct _format - typedef struct
 * @type: format
 * @f: the function associated
 */
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif
