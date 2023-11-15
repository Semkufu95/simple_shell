#include "main.h"
/**
 * _printf - a simple printf clone for the simple shell project.
 * @str: the input format string.
 * Return: nothing.
 */
void _printf(const char *str)
{
	size_t length;

	length = 0;
	while (*(str + length) != 0)
	{
		_putchar(*(str + length));
		length++;
	}
	fflush(stdout);
}


#include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to be printed
  * Return: On success 1, On error -1, errno is set appropiately.
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * _strlen - computes length of a string.
 * @str: input string
 * Return: string length
 */

int _strlen(char *str)
{
	int j, len;

	len = 0;
	for (j = 0; *(str + j) != '\0'; j++)
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - copies a source string into a destination string
 * @dest: pointer to destination string.
 * @src: pointer ro source string.
 * Return: point to new destination string
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	dest = "\0";
	return (ptr);
}

/**
 * _strcmp - compares two strings in custom.
 * Return: 0 if string is NULL else return compared string.
 * @strng1: string one
 * @strng2: string two to compare
 */

int _strcmp(const char *strng1, const char *strng2)
{
	int j;

	for (j = 0; strng1[j] == strng2[j]; j++)
	{
		if (strng1[j] == '\0')
			return (0);
	}
	return (strng1[j] - strng2[j]);
}
