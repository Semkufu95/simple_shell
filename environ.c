#include "main.h"

/**
 * shell_setenv - set environment variable.
 * @tokens: Array of tokens containing variable and value.
 * Return: nothing.
 */

void shell_setenv(char **tokens)
{
	if (tokens[1] == NULL || tokens[2] == NULL)
	{
		_printf("Usage: setenv <VARIABLE> <VALUE>\n");
		return;
	}
	if (setenv(tokens[1], tokens[2], 1) == -1)
	{
		perror("./hsh");
		return;
	}
}


/**
 * shell_unsetenv - unsets an environment variable.
 * @tokens: Array of tokens containing variable and value.
 * Return: nothing.
 */

void shell_unsetenv(char **tokens)
{
	if (tokens[1] == NULL)
	{
		_printf("Usage: unsetenv <VARIABLE>\n");
		return;
	}
	if (unsetenv(tokens[1]) == -1)
	{
		perror("./hsh");
		return;
	}
}
