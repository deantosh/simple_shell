/*
 * File: exit_shell.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include "main.h"

/**
 * exit_shell - Exits shell.
 * @argv: A list of arguments to pass to function.
 *
 * Return: 0 (success).
 */
int exit_shell(char **argv)
{
	(void)argv; /*suppress warning*/
	free_pp(argv); /*free mem*/
	exit(0);
}
