#include "main.h"

/**
  * cmd_execut - function to tokenize string to arguments
  * @command: a serie of instructions
  * Return: nothing (void)
  */
void cmd_execut(char *command)
{
	char *args[MAX_ARGS];
	int ac = 0;
	char *token;

	token = str_tok(command, " \t\n\"'`\\*&#");

	while (token != NULL)
	{
		args[ac++] = token;
		token = str_tok(NULL, " \t\n\"'`\\*&#");
	}
	args[ac] = NULL;

	execvp(args[0], args);
	perror("Error executing command");
	exit(1);
}
/**
  * handle_logical_operator - handles the && and ||
  * @input: command inputs
  * Return: void - nothing
  */

void handle_logical_operator(char *input)
{
	char *commands[MAX_COMMANDS];
	int cmd_count = 0, logical_operator = 1;
	char *token;
	int k, status;
	pid_t pid = fork();

	token = str_tok(input, ";");

	while (token != NULL)
	{
		commands[cmd_count++] = token;
		token = str_tok(NULL, ";");
	}
	for (k = 0; k < cmd_count; k++)
	{
		if (k > 0 && commands[k - 1][_strlen(commands[k - 1]) - 1] == '|')
		{
			logical_operator = 0;
		}
		/* pid_t pid = fork(); */

		if (pid == -1)
		{
			perror("Error forking");
			return;
		}
		else if (pid == 0)
		{
			cmd_execut(commands[k]);
		}
		else
		{
			waitpid(pid, &status, 0);
			if ((status == 0 && logical_operator == 1) || (status != 0
			&& logical_operator == 0))
				continue;
			else
				break;
		}
	}
}
