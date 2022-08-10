#include "main.h"

/**
 * _memcpy - copies n bytes of memory to buffer
 * @output: a buffer_t struct
 * @src: memory area to be copied
 * @n: number of bytes to be copied
 *
 * Return: number of bytes copied
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(output->buffer) = *(src + i);
		(output->len)++;

		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
		{
			(output->buffer)++;
		}
	}

	return (n);
}

/**
 * free_buffer - frees a buffer_t struct
 * @output: buffer to be freed
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * init_buffer - initializes a var of buffer_t
 *
 * Return: pointer to the initalized buffer
 */
buffer_t *init_buffer(void)
{
	buffer_t *output;

	output = malloc(sizeof(buffer_t));
	if (output == NULL)
		return (NULL);
	output->buffer = malloc(sizeof(char) * 1024);
	if (output->buffer == NULL)
	{
		free(output);
		return (NULL);
	}
	output->start = output->buffer;
	output->len = 0;

	return (output);
}
