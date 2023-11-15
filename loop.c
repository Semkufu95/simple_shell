#include"main.h"
/**
 * main - the loop for simple shell.
 * Return: always 0;
 */

int main(void)
{
	int status;
	char *input, **tokens, *buffer;
	ssize_t bytes, buff_size;
	const ssize_t BUFFSIZE = 1024;

	status = 1;
	if (isatty(STDIN_FILENO))
	{
		do {
			printf("($)");
			fflush(stdout);
			input = get_input();
			tokens = tokenizer(input);
			if (tokens[0])
			shell_executor(tokens);
			free(tokens);
			free(input);
		} while (status);
	}
	else
	{
		buff_size = BUFFSIZE;
		buffer = malloc(buff_size * sizeof(char));
		if (!buffer)
		perror("./hsh");
		bytes = read(STDIN_FILENO, buffer, BUFFSIZE);
		if ((int)bytes == -1)
			perror("./hsh");
		if ((int)bytes == 0)
			_strcpy(buffer, "\n");
		buffer[bytes] = '\0';
		input = buffer;
		tokens = tokenizer(input);
		shell_executor(tokens);
	}
	free(buffer);
	free(tokens);
	return (0);
}
