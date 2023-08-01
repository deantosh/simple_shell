/*
 * File: env.c
 * Author: Deantosh Daiddoh & Lucky Archibong
 */

#include  "main.h"

/**
 * print_env - Prints current environment.
 * @argv: A list of arguments to pass to function.
 *
 * Return: 0 (Success).
 */
int print_env(char **argv)
{
	int index;
	size_t nbyte;

	(void)argv; /*suppress unused variable warning*/

	for (index = 0; environ[index]; index++)
	{
		nbyte = strlen(environ[index]);
		write(STDOUT_FILENO, environ[index], nbyte);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * set_env - Sets the environment variable.
 * @argv: A list of arguments to pass to function.
 *
 * Return: 0 (success) or 1 (fails).
 */
int set_env(char **argv)
{
	char **env_var = NULL;
	char *new_value, *var_name = NULL, *var_value = NULL;
	int len, status, size;

	if (!argv[1] || argv[2])
		return (0);

	/*set values*/
	var_name = argv[1];
	var_value = argv[2];

	/*allocate memory of new value*/
	new_value = malloc(strlen(var_name) + strlen(var_value) + 2);
	if (new_value == NULL)
		return (-1);
	/*copy to the new value*/
	strcpy(new_value, var_name);
	strcat(new_value, "=");
	strcat(new_value, var_value);

	/*search to see if environ variable exists*/
	env_var = _getenv(var_name);
	if (env_var)
	{
		free(*env_var); /*empty it*/
		*env_var = new_value;
		return (0);
	}

	/*create a copy of the environ*/
	len = get_environ_len();
	size = len + 2; /*size of the new_environ*/
	status = add_var_to_environ(size, new_value);
	return (status);
}

/**
 * unset_env - Deletes environment variable from PATH.
 * @argv: The list of arguments to pass to the function.
 *
 * Return: 0 (success) or 1 (fails).
 */
int unset_env(char **argv)
{
	char **new_environ, **delete_var, *var_name;
	int index1 = 0, index2 = 0, len, result;

	var_name = argv[1];
	if (var_name == NULL)
		return (1);

	delete_var = _getenv(var_name); /*gets the environment var to delete*/
	if (delete_var == NULL)
		return (1);

	/*create a copy of the environ*/
	len = get_environ_len();
	new_environ = malloc(sizeof(char *) * len);
	if (new_environ == NULL)
		return (1);

	while (environ[index1])
	{
		result = strcmp(*delete_var, environ[index1]);
		if (result == 0)
		{
			index1++;
			continue;
		}
		new_environ[index2] = environ[index1];
		index1++;
		index2++;
	}
	environ = new_environ;
	environ[len] = NULL;
	return (0);
}
