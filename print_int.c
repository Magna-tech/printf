#include "main.h"

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
	unsigned long int a = n;

	if (n < 0)
	{
		a = -n;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[a % b];
		a /= b;
	} while (a != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
