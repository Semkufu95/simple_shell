#ifndef MAIN_H
#define MAIN_H

#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdio.h>

/* handling special chars */
#define MAX_COMMANDS 10
#define MAX_ARGS 64
#define MAX_ARGS_LENGTH 256

void cmd_execut(char *command);
void handle_cmd_separator(char *input);
void handle_logical_operator(char *input);

extern char **environ;

/**
 * struct built_ins - a structure for array of built-in functions.
 * @name: string name of the built-in function.
 * @func: pointer to named function.
 */

typedef struct built_ins
{
	const char *name;
	void (*func)(char **);
} builtin_t;

int main(void);
void shell_exit(char **);
void shell_help(char **);
void shell_executor(char **);
void shell_setenv(char **);
void shell_unsetenv(char **);
char **tokenizer(char *);
void shell_cd(char **);
void shell_env(char **);
char *get_input(void);
void _printf(const char *);
int _strcmp(const char *, const char *);
int _putchar(char);
char *scriptor(const char *);
int _strlen(char *);
char *_strcpy(char *, char *);
ssize_t shell_getline(char **, size_t *, int);
char *str_tok(char *, const char *);

#endif
