#include "main.h"

/**
 * manipulator - controls formats
 * @str: a string format
 * @ap: list of args
 *
 * Return: total number of arguments & size of base string
 */
int manipulator(const char *str, va_list ap)
{
	int size, i, j;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			j = perman(str, ap, &i);
			if (j == -1)
				return (-1);
			size += j;
			continue;
		}
		_putchar(str[i]);
		size += 1;
	}

	return (size);
}

/**
 * perman - handles the percentage format
 * @str: format string
 * @ap: list of args
 * @i: iterator
 *
 * Return: size of the number of elements printed
 */
int perman(const char *str, va_list ap, int *i)
{
	int size, j, num;
	format formats[] = {{'c', print_char}, {'s', print_str}};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);
	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	num = sizeof(format) / sizeof(formats[0]);
	for (size = j = 0; j < num; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(ap);
			return (size);
		}
	}
	_putchar('%');
	_putchar(str[*i]);

	return (2);
}
