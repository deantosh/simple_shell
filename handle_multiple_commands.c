/*
 * Author: Deantosh M Daiddoh
 * File: handle_multiple_command.c
 */

#include "main.h"

/**
 * command_loop - Iterates through the list of commands and executes them.
 * @argv: The list of arguments read from input.
 *
 * Return: execution status.
 **/
int command_loop(char **argv)
{
	int index, commands, command_tokens, ret = 0;
	int start_pos = 0, end_pos;
	char **argv_copy, *delim = ";";

	commands = num_commands(argv, delim);

	for (index = 0; index < commands; index++)
	{
		/*search for a command separator*/
		end_pos = is_command_separator(argv, delim, start_pos);

		/*get number of tokens for the command*/
		command_tokens = num_tokens(argv, start_pos);

		/*create a list copy*/
		argv_copy = create_list_copy(argv, start_pos, command_tokens);

		/*execute commands*/
		ret = command_parser(argv_copy);

		/*reset the start pos for the next command*/
		start_pos = end_pos + 1;
	}
	return (ret);
}

/**
 * create_list_copy - Creates a copy of a command from the command list.
 * @argv: The list of commands.
 * @start_pos: The start position of the command.
 * @num_tokens: The command tokens.
 *
 * Return: A pointer to the command copy (success) or NULL (fails).
 */
char **create_list_copy(char **argv, int start_pos, int num_tokens)
{
	char **argv_command, *delim = ";";
	int index1, end_pos, index2 = 0;

	/*get end of the command*/
	end_pos = is_command_separator(argv, delim, start_pos);
	/*allocate memory*/
	argv_command = malloc(sizeof(char *) * (num_tokens + 1));
	if (argv_command == NULL)
		return (NULL);

	for (index1 = start_pos; index1 < end_pos; index1++)
	{
		argv_command[index2] = malloc(sizeof(char) * (strlen(argv[index1]) + 1));
		if (argv_command[index2] == NULL) /*if it fails free mem*/
		{
			while (argv_command[index2])
			{
				free(argv_command[index2]);
				index2--;
			}
			free(argv_command);
			return (NULL);
		}
		strcpy(argv_command[index2], argv[index1]);
		index2++;
	}
	argv_command[index2] = NULL;
	return (argv_command);
}

/**
 * num_commands - Gets the number of commands.
 * @argv: The list of arguments read from input.
 * @delim: The character that separates commands.
 *
 * Return: number of args or 0 (none);
 */
int num_commands(char **argv, char *delim)
{
	int index = 0, count = 0, ret;

	while (argv[index])
	{
		ret = strncmp(argv[index], delim, 1);
		if (ret == 0)
		{
			index++;
			continue;
		}
		count++;
		index++;
	}
	return (count);
}

/**
 * is_command_separator - Checks if separator is present in the list.
 * @argv: A list of arguments to execute.
 * @delim: The separator to search.
 * @start_pos: The command start position.
 *
 * Return: delim pos (found) or 0 (not found)
*/
int is_command_separator(char **argv, char *delim, int start_pos)
{
	int ret, index = 0;

	index = start_pos;

	while (argv[index])
	{
		ret = strncmp(argv[index], delim, 1);
		if (ret == 0)
			return (index);
		index++;
	}
	return (index); /*end of list*/
}

/**
 * num_tokens - Gets the number of tokens for a command in a command list.
 * @argv:  The list of commands.
 * @start_pos: The start of the command.
 *
 * Return: number token (success) or 0 (none).
 */
int num_tokens(char **argv, int start_pos)
{
	int index, end_pos, tokens = 0;
	char *delim = ";";

	/*gets the end of first command*/
	end_pos = is_command_separator(argv, delim, start_pos);
	for (index = start_pos; index < end_pos; index++)
		tokens++;
	return (tokens);
}
