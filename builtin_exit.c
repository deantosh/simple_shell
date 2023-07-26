/*
 * File: exit_shell.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * exit_shell - Exits shell.
 * @argv: A pointer to the list of arguments.
 *
 * Return: 2 (success) or exit_status (if provided).
 */
int exit_shell(char **argv)
{
	int exit_status;

	if (argv[1]) /*check if exit status is provided*/
	{
		exit_status = atoi(argv[1]);
		return (exit_status);
	}
	exit (0); /*if exit status not provided*/
}
