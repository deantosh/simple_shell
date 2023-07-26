/*
 *File: main.c
 *Author: Deantosh Daiddoh &Lucky Archibong
 */
#include "main.h"

/**
 *get_pwd_env - Update the PWD environment
 *        to current working directory.
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
int change_directory(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("chdir");
        return (-1);
    }

    get_pwd_env();
    return (0);
}