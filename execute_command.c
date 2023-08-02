/*
 * File: execute_command.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * execute_builtin_command - Executes commands builtin
 *				to the program.
 * @argv: The list of arguments used by the command.
 *
 * Return: 0 (success), 1 (fails) and result.
 */
int execute_builtin_command(char **argv)
{
	/*declare variables*/
	int index, builtin_len, status, result;
	char *command = argv[0];
	builtin_s cmd_list[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", change_directory},
		{NULL, NULL}
	};

	/*check if command provided exists*/
	if (command == NULL)
		return (1);

	/*get len of the cmd_list*/
	builtin_len = get_builtin_len(cmd_list);
	for (index = 0; index < builtin_len; index++)
	{
		status = strcmp(cmd_list[index].name, command);
		if (status == 0)
		{
			/*execute command*/
			result = cmd_list[index].func(argv);
			return (result);
		}
	}
	return (1);
}

/**
 * get_builtin_len - Gets the number of items in a list.
 * @cmd_list: The array of commands.
 *
 * Return: The length of the list or 0 (none);
 */
int get_builtin_len(builtin_s cmd_list[])
{
	/*declare variable*/
	int index = 0;

	while (cmd_list[index].name != NULL)
		index++;

	return (index);
}

/**
 * execute_external_command - Executes system commands.
 * @argv: The list of arguments used by the command.
 *
 * Return: 0 (success) or 1 (fails).
 */
int execute_external_command(char **argv)
{
	char *command = NULL, *full_command = NULL;
	pid_t pid;
	int status, exit_status;

	if (argv)
	{
		command = argv[0];
		full_command = get_full_path(command);
		if (full_command == NULL)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			return (127);
		}
		if (full_command)
		{
			/*create a child process*/
			pid = fork();
			if (pid == 0)
			{
				/*execute command*/
				if (execve(full_command, argv, NULL) == -1)
					exit(1);
			}
			else
			{
				wait(&status);
				free(full_command);/*free memory*/
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					return (exit_status);
				}
			}
		}
	}
	return (0);
}
