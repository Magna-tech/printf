#include "main.h"

/**
 * cleanup - performs cleanups for _printf
 * @args: list of args
 * @output: a buffer_t struct
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * print - reads through the format string
 * @format: char string to be printed
 * @args: list of args
 * @output: a buffer_t struct
 *
 * Return: number of character stored to output
 */
unsigned int print(const char *format, va_list args, buffer_t *output)
{
	int i, ret = 0;
	char tmp;
	unsigned char len;
	unsigned int (*f)(va_list, buffer_t *);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			f = manipulator(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - prints a formated string
 * @format: the string given
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	buffer_t *output;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);
	va_start(args, format);

	ret = print(format, args, output);

	return (ret);
}
