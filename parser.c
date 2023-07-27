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
	int exec_status;

	/*execute builtin command*/
	exec_status = execute_builtin_command(argv);
	if (exec_status == 0)/*success*/
	{
		free_pp(argv);/*free memory allocated*/
		return (exec_status);
	}
	else if (exec_status == 1)
	{
		/*execute external program*/
		exec_status = execute_external_command(argv);
		if (exec_status == 0)/*success*/
		{
			free_pp(argv);/*free memory allocated*/
			return (0);
		}
		else /*if not command*/
		{
			perror("Error:");
			free_pp(argv);
		}
		return (0);
	}
	else /*exit shell*/
	{
		free_pp(argv);
		return (exec_status);
	}
}
