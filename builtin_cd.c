/*
 *File: main.c
 *Author: Deantosh Daiddoh &Lucky Archibong
 */
#include "main.h"

/**
 *get_pwd_env - Update the PWD environment
 *         to current working directory.
 */

void get_pwd_env(void)
{
	char c_w_d[1024];

	if (getcwd(c_w_d, sizeof(c_w_d)) != NULL)
	{
		setenv("PWD", c_w_d, 1);
	}
	else
	{
		perror("getcwd");
	}
}

/**
 *change_directory - Change current working directory.
 *@argv: A list of arguments to pass to the function.
 *
 *Return: On success, 0. failed, -1
 */
int change_directory(char **argv)
{
	char *path = argv[1];

	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}
	get_pwd_env();
	return (0);
}
