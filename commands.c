#include "main.h"

/**
 * shell_executor - executes a parsed command.
 * @args: the parsed array of command, with args.
 * Return: NULL
 */

void shell_executor(char **args)
{
	int j, status;
	pid_t pid;
	ssize_t builtin_size;
	builtin_t builtins_list[] = {
		{"help", shell_help},
		{"exit", shell_exit},
		{"cd", shell_cd},
		{"env", shell_env},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
	};
	builtin_size = sizeof(builtins_list) / sizeof(builtin_t);
	for (j = 0; j < (int)builtin_size; j++)
	{
		if (_strcmp(args[0], builtins_list[j].name) == 0)
		{
			builtins_list[j].func(args);
			return;
		}
	}
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		exit(1);
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("./hsh");
		exit(1);
	}
}
