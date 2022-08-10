#include "main.h"

/**
 * convert_str - converts an arg into a string
 * @args: va_list of args to be converted
 * @output: a buffer_t struct containing a char array
 *
 * Return: the number of bytes stored in the buffer
 */
unsigned int convert_str(va_list args, buffer_t *output)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));
	for (size = 0; *(str + size);)
		size++;
	while (*str != '\0')
	{
		ret += _memcpy(output, str, 1);
		str++;
	}

	return (ret);
}

/**
 * convert_c - converts an arg to an unsigned char
 * @args: va_list of args
 * @output: a buffer_t struct containing a char array
 *
 * Return: number of bytes store to the buffer
 */
unsigned int convert_c(va_list args, buffer_t *output)
{
	char c;
	unsigned int ret = 0;

	c = va_arg(args, int);

	ret += _memcpy(output, &c, 1);

	return (ret);
}

/**
 * convert_per - stores a percent sign to a buffer
 * @args: va_list pointing to argument to be converted
 * @output: a buffer_t struct containing a char array
 *
 * Return: always 1, the # of bytes stored to the buffer
 */
unsigned int convert_per(va_list args, buffer_t *output)
{
	char percent = '%';
	unsigned int ret = 0;

	(void)args;

	ret += _memcpy(output, &percent, 1);

	return (ret);
}

/**
 * convert_int - converts an arg to a signed int
 * @args: va_list of args
 * @output: a buffer_t struct containing a char array
 *
 * Return: number of bytes stored to the buffer
 */
unsigned int convert_int(va_list args, buffer_t *output)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char space = ' ';

	d = va_arg(args, int);

	for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
		count++;
	if (d >= 0)
		ret += _memcpy(output, &space, 1);

	return (ret);
}
