#include "main.h"
#define INIT_BUF_SIZE 120

/*Function prototypes */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_line(char **lineptr, size_t *n, char *buf, size_t buf_size);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

/**
 *re_alloc - Reallocates a memory block using malloc and free.
 *
 *@ptr: A pointer to the memory previously allocated.
 *@old_size: The size in bytes of the original space for ptr.
 *@new_size: The size in bytes for the new memory block.
 *Return: If new_size == old_size - ptr.
 *        If new_size == 0 and ptr is not NULL - NULL.
 *        Otherwise - a pointer to the reallocated memory block.
 */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	char *original_ptr, *new_ptr_fill;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	original_ptr = ptr;
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr_fill = new_ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr_fill[i] = *original_ptr++;

	free(ptr);
	return (new_ptr);
}

/**
 *assign_line - Reassigns the lineptr variable for custom_getline.
 *
 *@lineptr: A buffer to store an input string.
 *@n: The size of lineptr.
 *@buf: The string to assign to lineptr.
 *@buf_size: The size of buf.
 */
void assign_line(char **lineptr, size_t *n, char *buf, size_t buf_size)
{
	if (*lineptr == NULL || *n < buf_size)
	{
		*n = buf_size > INIT_BUF_SIZE ? buf_size : INIT_BUF_SIZE;
		*lineptr = buf;
	}
	else
	{
		free(*lineptr);
		*lineptr = buf;
	}
}

/**
 *custom_getline - Reads input from a stream.
 *
 *@lineptr: A buffer to store the input.
 *@n: The size of lineptr.
 *@stream: The stream to read from.
 *
 *Return: The number of bytes read.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buf;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);

	input = 0;

	buf = malloc(sizeof(char) * INIT_BUF_SIZE);
	if (!buf)
		return (-1);

	while (1)
	{
		r = read(fileno(stdin), &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buf);
			return (-1);
		}

		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= INIT_BUF_SIZE)
			buf = re_alloc(buf, input, input + 1);

		buf[input] = c;
		input++;

		if (c == '\n')
			break;
	}

	buf[input] = '\0';

	assign_line(lineptr, n, buf, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}