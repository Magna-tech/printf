#include "main.h"

/**
 * manipulator - matches conversion specifiers to functions
 * @specifier: pointer to a conversion specifier
 *
 * Return: pointer to the function, NULL on failure
 */
unsigned int (*manipulator(const char *specifier))(va_list, buffer_t *)
{
	int i;
	converter_t converters[] = {
		{'c', convert_c}, {'s', convert_str},
		{'d', convert_int}, {'i', convert_int},
		{'%', convert_per}, {0, NULL}};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}
