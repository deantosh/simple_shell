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
		/*if arg not a number*/
		if (exit_status <= 0)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", argv[1]);
			return (0);
		}
		else /*if num*/
		{
			return (exit_status);
		}
	}
	/*exit without status*/
	return (2);
}
