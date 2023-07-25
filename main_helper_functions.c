/*
 * Author: Deantosh M Daiddh & Lucky Archibong.
 * File: helper_functions.c
*/

#include "main.h"

/**
 * _strtok - Create a list of tokens from a string.
 * @src: A pointer to the string to convert.
 * @delim: A pointer to the character that separates the tokens.
 *
 * Return: A pointer to the token or NULL (if not found).
 */
char *_strtok(char *src, const char *delim)
{
	/*remember initial str on 2nd call*/
	static char *next_token;
	char *token;

	if (src == NULL)
		src = next_token;
	if (src == NULL)
		return (NULL);
	/*for the delim at the beginning of the string*/
	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++; /*move pointer*/
			continue;
		}
		/*if end of src*/
		if (*src == '\0')
			return (NULL);
		break;
	}
	token = src; /*pos of token*/
	while (1)
	{
		if (*src == '\0')
		{
			next_token = src;
			return (token);
		}
		if (is_delim(*src, delim))
		{
			/*replace delim with '\0'*/
			*src = '\0';
			next_token = src + 1; /*set pos of next token*/
			return (token);
		}
		src++; /*move pointer*/
	}
}

/**
 * is_delim - Checks if a character is a given delimiter.
 * @ch: The character to check.
 * @delim: A pointer to the searched pattern.
 *
 * Return: 1 (match) or 0 (match not found)
*/
int is_delim(char ch, const char *delim)
{
	while (*delim != '\0')
	{
		if (ch == *delim)
			return (1);
		delim++; /*move pointer*/
	}
	return (0);
}

/**
 * _strlen - Get the length of a string.
 * @str: The string.
 *
 * Return: len
 */
int _strlen(char *str)
{
	int index = 0;

	while (str[index] != '\0')
		index++;

	return (index);
}
