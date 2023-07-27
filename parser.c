/*
 * Authors: Deantosh Daiddoh & Lucky Archibong.
 * File: command_args_parser.c
 */

#include "main.h"

/**
 * command_parser - Passes the argument list to builtin
 *                  and external execute command functions.
 * @argv: The argument list.
 *
 * Return: 0 Always (success) or 2 (exit shell)
 *		exit_status(exit shell with status) or 1(fails).
 */
int command_parser(char **argv)
{
	/*declare variables*/
	int exec_status, exit_status;

	/*execute builtin command*/
	exec_status = execute_builtin_command(argv);
	if (exec_status == 0)/*success*/
	{
		free_pp(argv);/*free memory allocated*/
		return (0);
	}
	if (exec_status != 1)
	{
		if (exec_status == -1)
		{
			free_pp(argv);
			return (1);
		}
		else if (exec_status == 2)
		{
			free_pp(argv);
			return (2);
		}
		else
		{
			exit_status = exec_status;
			free_pp(argv);
			return (exit_status);
		}
	}

	/*execute system command*/
	exec_status = execute_external_command(argv);
	if (exec_status == 0)/*success*/
	{
		free_pp(argv);/*free memory allocated*/
		return (0);
	}
	else /*command not found*/
	{
		perror("Error:");
		free_pp(argv);
	}
	return (0);
}
