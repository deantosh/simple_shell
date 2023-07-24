/*
 * File: main.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"
#define BUFSIZE 1024

/**
 * ret_line - Assigns the line var for custom_getline
 * @lineptr: Buffer that stores the input string
 * @n: Size of lineptr
 * @buffer: String that is been called to lineptr
 * @j: Size of buffer
 *
 * Description:
 * This function assigns the lineptr variable for custom_getline.
 * It is responsible for updating the lineptr buffer with the input string
 * and handling memory reallocation if needed.
 */
void ret_line(char **lineptr, size_t *n, char *buffer, size_t j);

/**
 * read_input - Reads input from the stream
 * @input: Buffer to store the input
 * @stream: Stream to read from
 *
 * Return: The number of bytes read
 *
 * Description:
 * This function reads input from the stream and stores it in the input buffer.
 * It returns the number of bytes read or -1 on error or end of file.
 */
ssize_t read_input(char **input, FILE *stream);

/**
 * custom_getline - Read input from stream
 * @lineptr: Buffer that stores the input
 * @n: Size of lineptr
 * @stream: Stream to read from
 *
 * Return: The number of bytes read
 *
 * Description:
 * This function reads input from the stream and stores it in lineptr.
 * If no input is read, it returns -1.
 * If input is read successfully, it updates lineptr and n accordingly.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

/**
 * ret_line - Assigns the line var for custom_getline
 * @lineptr: Buffer that stores the input string
 * @n: Size of lineptr
 * @buffer: String that is been called to lineptr
 * @j: Size of buffer
 */
void ret_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		*n = (j > BUFSIZE) ? j : BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		*n = (j > BUFSIZE) ? j : BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * read_input - Reads input from the stream
 * @input: Buffer to store the input
 * @stream: Stream to read from
 *
 * Return: The number of bytes read
 */
ssize_t read_input(char **input, FILE *stream)
{
	size_t input_pos;
	char current_char = 'x';
	int read_result;

	fflush(stream);

	*input = malloc(sizeof(char) * BUFSIZE);
	if (!*input)
	{
		return (-1); /* Return -1 on memory allocation failure */
	}

	while (current_char != '\n')
	{
		read_result = fgetc(stream);
		if (read_result == -1 || (read_result == 0 && input_pos == 0))
		{
			free(*input);
			return (-1); /* Return -1 on error or end of file */
		}

		if (read_result == 0 && input_pos != 0)
		{
			input_pos++;
			break; /* Break loop if end of file is reached */
		}

		if (input_pos >= BUFSIZE)
		{
			char *new_buffer = realloc(*input, input_pos + 1);

			if (!new_buffer)
			{
				free(*input);
				return (-1); /* Return -1 on memory reallocation failure */
			}

			*input = new_buffer;
		}

		current_char = (char)read_result;
		(*input)[input_pos] = current_char;
		input_pos++;
	}

	(*input)[input_pos] = '\0';

	return (input_pos); /* Return the number of bytes read */
}

/**
 * custom_getline - Read input from stream
 * @lineptr: Buffer that stores the input
 * @n: Size of lineptr
 * @stream: Stream to read from
 *
 * Return: The number of bytes read
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{

	ssize_t input_size = read_input(lineptr, stream);

	if (input_size == -1)
	{
		return (-1); /* Return -1 on error or end of file */
	}

	ret_line(lineptr, n, *lineptr, input_size);

	return (input_size); /* Return the number of bytes read */
}