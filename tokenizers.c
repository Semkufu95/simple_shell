#include "main.h"

/**
  * str_tok - A Function to tokenize a string
  * @strng: string to be tokenized
  * @delimiter: string containing a set of characters (delimiters)
  * Return: token
  */

char *str_tok(char *strng, const char *delimiter)
{
	char *token_start;
	char *token_end;
	int parameter = 0;

	if (strng != NULL)
	{
		token_end = strng;
	}
	if (token_end == NULL || *token_end == '\0')
	{
		return (NULL);
	}
	token_start = token_end;
	while (*token_end != '\0')
	{
		const char *delim = delimiter;

		while (*delim != '\0')
		{
			if (*token_end == *delim)
			{
				parameter = 1;
			break;
			}
			delim++;
		}
		if (parameter)
		{
			token_end++;
			break;
		}
		token_end++;
	}
	return (token_start);
}

#include "main.h"
/**
 * tokenizer - splits input lines into tokens (words - commands/ args).
 * @inpt: the input string line.
 * Return: array of tokens.
 */

char **tokenizer(char *inpt)
{
	int len, num_tokens;
	char **tokens, *token;
	const char *DELIM = " \t\r\n\a";
	const int TK_LIM = 64;

	len = 0, num_tokens = TK_LIM;
	tokens = malloc(num_tokens * sizeof(char *));
	if (!tokens)
	{
		perror("hsh: failed to allocate memory");
		exit(1);
	}
	token = str_tok(inpt, DELIM);
	while (token)
	{
		tokens[len] = token;
		len++;
		if (len >= num_tokens)
		{
			num_tokens += TK_LIM;
			tokens = realloc(tokens, num_tokens * sizeof(char *));
			if (!tokens)
			{
				perror("./hsh");
				exit(1);
			}
		}
		token = str_tok(NULL, DELIM);
	}
	tokens[len] = NULL;
	return (tokens);
}
