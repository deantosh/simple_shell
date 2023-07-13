/*
 * File: execute_command.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * execute_command - Executes system commands.
 * @argv: The list of arguments used by the command.
 *
 * Return: 1 (success).
 */
void execute_command(char **argv)
{
	char *command = NULL, *full_command = NULL;
	int status;
	pid_t pid;

	if (argv)
	{
		command = argv[0];
		full_command = get_full_path(command);

		if (full_command)
		{
			/*create a child process*/
			pid = fork();

			if (pid == 0)
			{
				if (execve(full_command, argv, NULL) == -1)
				{
					perror(argv[0]);
					exit(1);
				};
			}
			else if (pid > 0)
			{
				wait(&status);
			}
			else
				perror("Error:");

			free(full_command); /*free memory*/
		}
	}
}
