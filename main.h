#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
 
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

/**
 * struct buffer_s - a type def for a buffer
 * @buffer: a pointer to a char array
 * @start: pointer to the start of buffer
 * @len: length of the string stored in buffer
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - a new type defining a converter
 * @specifier: a char representing a conversion specifier
 * @func: pointer to a conversion function
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *);
} converter_t;

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
void free_buffer(buffer_t *output);
buffer_t *init_buffer(void);

int _printf(const char *format, ...);
unsigned int print(const char *format, va_list args, buffer_t *output);
unsigned int (*manipulator(const char *specifier))(va_list, buffer_t *);
unsigned int convert_str(va_list args, buffer_t *output);
unsigned int convert_c(va_list, buffer_t *);
unsigned int convert_per(va_list, buffer_t *);
unsigned int convert_int(va_list, buffer_t *);
void cleanup(va_list args, buffer_t *output);
unsigned int print_int(va_list ap);
char *itoa(long int n, int b);

#endif
