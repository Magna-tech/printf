#include "main.h"

/**
 * print_int - prints an integer
 * @ap: list of args
 *
 * Return: Length of the numbers in decimal
 */


int print_int(va_list ap)
{
	char *i;
	int size;

	i = itoa(va_arg(ap, int), 10);

	size = print((i != NULL) ? i : "NULL");

	return (size);
}

/**
 * itoa - integer to ascii
 * @n: num
 * @b: base
 *
 * Return: char
 */
char *itoa(long int n, int b)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = n;

	if (n < 0)
	{
		n = n;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
