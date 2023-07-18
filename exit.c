/*
 * File: exit_shell.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * exit_shell - Exits shell.
 * @argv: A list of arguments to pass to function.
 *
 * Return: 2 (success) or exit_status (if provided).
 */
int exit_shell(char **argv)
{
	int exit_status;
	(void)argv; /*suppress warning*/

	if (argv[1]) /*exit with status code*/
	{
		exit_status = atoi(argv[1]);
		return (exit_status);
	}
	return (2); /*if exit with no status*/
}
