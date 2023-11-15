#include "main.h"

/**
 * shell_cd - changing current working directory.
 * @args: passed in arguments.
 * Return: nothing.
 */

void shell_cd(char **args)
{
	char *home_dirctry, cwd[4096];

	if (_strcmp(args[0], "cd") == 0)
	{
		if (!args[1])
		{
			home_dirctry = getenv("HOME");
			if (home_dirctry == NULL)
			{
				perror("./hsh");
				return;
			}
			else if (chdir(home_dirctry) != 0)
			{
				perror("./hsh");
				return;
			}
		}
		else if (chdir(args[1]) != 0)
			perror("./hsh");
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("./hsh");
		return;
	}
	if (setenv("PWD", cwd, 1) != 0)
	{
		perror("./hsh");
		return;
	}
}

#include "main.h"

/**
 * shell_help - prints our simple shell's help text.
 * @args: pased args to the shell's terminal.
 * Return: nothing (void)
 */

void shell_help(char **args)
{
	char *help_txt;

	help_txt =
		"hsh: A simple C shell to demonstrate comprehension in low level programming.\n"
		"The followwing are built in functions:\n"
		"1: cd: Change your working directory.\n"
		"2: exit: exit the simple shell.\n"
		"3: help: Display this help text.\n"
		"try help <n> to learn to use built-ins, where n is a number above.\n"
		;
	if (!args[1])
		_printf(help_txt);
	else
	{
		switch (atoi(args[1]))
		{
			case 1:
				_printf("__CD__\nUsage: cd <directory-path>\n");
				break;
			case 2:
				_printf("__EXIT__\nUsage: exit(n), default exit(0)\n");
				break;
			case 3:
			_printf("__HELP__\nDisplay help txt\n");
			_printf(help_txt);
			break;

			default:
			_printf("unknown help option\n");
			break;
		}
	}
}


#include "main.h"
/**
 * shell_exit - exits the simple shell.
 * @args: array of args passed.
 * Return: nothing.
 */

void shell_exit(char **args)
{
	int j;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			for (j = 0; args[1][j] != 0; j++)
			{
				if (args[1][j] < '0' || args[1][j] > '9')
				{
					_printf("exit: Illegal number\n");
					return;
				}
			}
			exit(atoi(args[1]));
		}
		exit(0);
	}
}

#include "main.h"
#define CHUNK 1024


char *buff_helper(char *buffer, size_t *len, size_t pos);

/**
 * shell_env - prints the environment.
 * @tokens: passed tokens which are of no use.
 * Return: nothing.
 */

void shell_env(char **tokens)
{
	char **env;
	char *var, *buffer;
	size_t len, pos;
	(void)tokens;

	len = CHUNK;
	pos = 0;
	buffer = malloc(len * sizeof(char));
	if (!buffer)
	{
		perror("./hsh");
		exit(1);
	}
	len = 0;
	for (env = environ; *env != NULL; env++)
	{
		var = *env;
		while (*var != '\0')
		{
			buffer[pos] = *var;
			var++, pos++;
			buffer = buff_helper(buffer, &len, pos);
		}
		buffer[pos] = '\n';
		pos++;
		buffer = buff_helper(buffer, &len, pos);
	}
	buffer[pos] = '\0';
	_printf(buffer);
	free(buffer);
}

/**
 * buff_helper - reallocated buffer memory whenever necessary.
 * @buffer: ponter to buffer.
 * @len: current size of buffer.
 * @pos: tracker of position to add chars.
 * Return: pointer to new or old buffer.
 */

char *buff_helper(char *buffer, size_t *len, size_t pos)
{
	char *new_buffer;

	new_buffer = NULL;

	if (pos >= *len)
	{
		*len += CHUNK;
		new_buffer = realloc(buffer, *len * sizeof(char));
		if (!new_buffer)
		{
			perror("./hsh");
			exit(1);
		}
		return (new_buffer);
	}
	return (buffer);
}
