#include "main.h"

/**
  * get_input - reads input lines and pass them to functions.
  * Return: pointer to input string line.
  */

char *get_input(void)
{
	char *input;
	size_t buff_length;
	ssize_t strlen;

	buff_length = 0;
	strlen = shell_getline(&input, &buff_length, fileno(stdin));
	if (strlen < 0)
	{
		perror("./hsh");
		exit(1);
	}
	return (input);
}

#include "main.h"

/**
 * init_buffer - initializes buffer.
 * @linepntr: pointer to line;
 * @bs: buffer size.
 * Return: nothing.
 */

void init_buffer(char **linepntr, size_t *bs)
{
	const ssize_t BUFFSIZE = 1024;

	*bs = BUFFSIZE;
	*linepntr = malloc(*bs * sizeof(char));
	if (*linepntr == NULL)
	{
		perror("./hsh");
		exit(1);
	}
}

/**
 * remove_comment - removes comment line beginning with '\#'
 * @line: the line to remove, if a comment.
 * Return: NULL.
 */

void remove_comment(char *line)
{
	char *comment_pos = strchr(line, '#');

	if (comment_pos != NULL)
		*comment_pos = '\0';
}

/**
 * shell_getline - reading lines from user input.
 * @linepntr: pointer to var for input line.
 * @bs: size of buffer
 * @fide: file descriptor.
 * Return: bytes of the read line.
 */

ssize_t shell_getline(char **linepntr, size_t *bs, int fide)
{
	ssize_t bytes = 0;
	size_t pos = 0;
	char *new_pntr = NULL;
	const ssize_t BUFFSIZE = 1024;

	init_buffer(linepntr, bs);
	while (1)
	{
		if (pos >= *bs)
		{
			*bs += BUFFSIZE;
			new_pntr = realloc(*linepntr, *bs * sizeof(char));
			if (new_pntr == NULL)
			{
				perror("./hsh");
				exit(1);
			}
			*linepntr = new_pntr;
		}
		bytes = read(fide, (*linepntr) + pos, 1);
		if (bytes == -1)
		{
			perror("./hsh");
			exit(1);
		}
		else if (bytes == 0 || (*linepntr)[pos] == '\n')
			break;
		pos++;
	}
	if (bytes == 0 && pos == 0)
		return (-1);
	(*linepntr)[pos] = '\0';
	remove_comment(*linepntr);
	return (pos);
}
