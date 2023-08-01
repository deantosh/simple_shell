/*
 * File: env_helper_functions.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include  "main.h"

/**
 * add_var_to_environ - creates a copy of the environment variable.
 *					not add NULL.
 * @size: The size on the new_environ.
 * @new_value: The environ variable to add to the created environ.
 * Return: 0 (success) or 1 (fails).
*/
int add_var_to_environ(int size, char *new_value)
{
	char **new_environ;
	int index;

	new_environ = malloc(sizeof(char *) * size);
	if (new_environ == NULL)
	{
		free(new_value);
		return (1);
	}

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(strlen(environ[index]) + 1);
		if (new_environ[index] == NULL)
		{
			while (index >= 0)
			{
				free(new_environ[index]);
				index--;
			}
			free(new_environ);
			return (1);
		}
		strcpy(new_environ[index], environ[index]); /*save a copy*/
	}
	environ = new_environ; /*point to new mem*/
	environ[index] = new_value;
	environ[index + 1] = NULL;
	return (0);
}

/**
 * get_environ_len -  Gets the number of environment variables.
 *
 * Return: The length of environment variable.
 */
int get_environ_len(void)
{
	int index = 0;

	while (environ[index])
		index++;

	return (index);
}

/**
 * free_environ - frees the environ copy.
 *
 * Return: void.
 */
void free_environ(void)
{
	int index = 0;

	while (environ[index])
	{
		free(environ[index]);
		index++;
	}
	free(environ);
}

/**
 * _getenv - Gets the specified environment string.
 * @name: The variable name to search.
 *
 * Return: A pointer to the value or NUll (not found).
 */
char **_getenv(const char *name)
{
	int index, len, result;

	len = strlen(name);
	while (environ[index])
	{
		result = strncmp(name, environ[index], len);
		if (result == 0)
			return (&environ[index]);
		index++;
	}
	return (NULL);
}
