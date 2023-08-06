/*
 * Author: Lucky Archibong && Deantosh Daiddoh
 * File: custom_getline.c
 */

#include "main.h"

/**
 * custom_getline - Reads a line from stream and stores value.
 * @lineptr: A pointer to store the read line.
 * @n:A pointer to store the size of the read line.
 * @stream: A pointer to the file to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	ssize_t n_read = getline(lineptr, &bufsize, stream);

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		errno = EINVAL; /* Invalid argument */
		return (-1);
	}
	if (n_read == -1)
	{
		if (feof(stream))
			errno = 0; /* Clear any previous errors caused by EOF */
		else
		perror("getline");
	}

	return (n_read);
}
