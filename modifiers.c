#include "main.h"

/**
 * _strlen - calculate length of string
 * @str: string
 *
 * Return: length of the string
 */
int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print - prints a character
 * @str: string to be printed
 *
 * Return: string length
 */
int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		_putchar(str[i]);
	}

	return (0);
}

/**
 * print_char - prints characters
 * @ap: list of va_list
 *
 * Description: print characters using %c format
 * Return: 1
 */
int print_char(va_list ap)
{
	int i;

	i = va_arg(ap, int);

	_putchar(i);

	return (1);
}

/**
 * print_str - prints a string
 * @ap: va_list
 *
 * Return: string length
 */
int print_str(va_list ap)
{
	char *j;
	int j_len;

	j =  va_arg(ap, char*);
	j_len = print((j != NULL) ? j : "(NULL)");

	return (j_len);
}
