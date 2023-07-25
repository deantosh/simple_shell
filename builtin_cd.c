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
 *@path: The path to change to.
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
<<<<<<< HEAD:builtin_cd.c
=======

/**
 *executor - Entry point of the program.
 *@argc: The number of command-line arguments.
 *@argv: An array of strings containing the command-line arguments.
 *
 *Return: On success, 0. On incorrect usage or error, 1.
 */

int executor(int argc, char **argv)
{
    char *home_dir = getenv("HOME");

    /*if arg is not given, change directory $PATH to $HOME*/
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "~") == 0))
    {
        change_directory(home_dir);
    }
    else if (argc == 2)
    /*change the directory to the specified $PATH*/
    {
        if (change_directory(argv[1]) == -1)
        {
            fprintf(stderr, "bad command");
            return (1);
            /*return a non zero value to indicate error*/
        }
    }
    else
    {
        fprintf(stderr, "usage: %s[path]\n", argv[0]);
        return (1);
        /*To indicate incorrect, i had to return non-negative value*/
    }

    return (0);
}
>>>>>>> 81607af6c021689b10c6e9e6819635afe3432458:change_directory.c
