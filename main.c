/*
 * File: main.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * main - Entry point.
 *
 * Return: 0 Always (success);
 */
int main(void)
{
	char **argv, *str = NULL;
	size_t n = 0;
	ssize_t n_bytes;
	int exec_status;

	while (1)
	{
		/*execute on interactive mode*/
		if (isatty(STDIN_FILENO))
			printf("%s ", PROMPT);

		/*read from stdin stream*/
		n_bytes = getline(&str, &n, stdin);
		if (n_bytes == -1)
		{
			free(str);
			/*new line character*/
			return (0);
		}
		/*pass str to function to create argv*/
		argv = str_parser_to_create_av(str, n_bytes);

		/*pass args for execution*/
		exec_status = command_parser(argv);
		if (exec_status)
		{
			/*exit without status*/
			if (exec_status == 2)
				return (2);
			if (exec_status == -1)
				return (0);
		}
	}
	return (0);
}

/**
 * str_parser_to_create_av - Passes the str to create_av function
 *                           to create argv.
 * @str: The string read from the stdin stream.
 * @bytes: The number of bytes read.
 *
 * Return: argv (success) or NULL (fails).
*/
char **str_parser_to_create_av(char *str, ssize_t bytes)
{
	char **argv, *str_copy;
	const char *delim = " \n";
	ssize_t size;
	int num_tokens;

	/*size of str_copy*/
	size = bytes + 1;
	/*allocate memory for str_copy*/
	str_copy = malloc(sizeof(char) * size);
	if (str_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
	/*create a copy of str*/
	strcpy(str_copy, str);
	num_tokens = get_token(str, delim);
	argv = create_av(str_copy, num_tokens, delim);
	free(str_copy);
	return (argv);
}

/**
 * get_token - Gets the number of tokens in a string
 * @str: String to tokenize.
 * @delim: Character used to separate the tokens.
 *
 * Return: The number of tokens.
 */
int get_token(char *str, const char *delim)
{
	char *token;
	int num_tokens = 0;

	token = _strtok(str, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = _strtok(NULL, delim);
	}
	num_tokens++;

	return (num_tokens);
}

/**
 * create_av - Converts a string into an array arguments.
 * @str: The string to convert.
 * @tokens: The number of string tokens.
 * @delim: The character used to separate arguments in a string.
 *
 * Return: A pointer to the allocated mem.
 */
char **create_av(char *str, int tokens, const char *delim)
{
	char **argv;
	char *token;
	int index;

	/*allocate mem for list of tokens*/
	argv = malloc(sizeof(char *) * tokens);

	token = _strtok(str, delim);
	for (index = 0; token != NULL; index++)
	{
		/*allocate memory for each token*/
		argv[index] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[index], token);
		token = _strtok(NULL, delim);
	}
	argv[index] = NULL;
	return (argv);
}
