#include "blejam.h"

/**
 * find_environment - this the the get environ builtin.
 * @myenv: enironment variable
 * Return: Null
 *
 *
 */

char *find_environment(const char *myenv)
{
	int bj = 0;
	char *bjkey;

	while (environ[bj])
	{
		bjkey = strtok(environ[bj], "=");
		if (strcmp(myenv, bjkey) == 0)
		return (strtok(NULL, "\n"));
		bj++;
	}
	return (NULL);
}

/**
 * tokenilize - split the string in tokens.
 * @buff: buffer.
 * @delt: delete.
 * Return: return tokens.
 *
 *
 *
 */

char **tokenilize(char *buff, char *delt)
{
	char **toks;
	char *tok;
	int jb = 0;

	toks = malloc(sizeof(char *) * 1024);
	if (toks == NULL)
	{
		perror("mallocErr");
		exit(EXIT_FAILURE);
	}
	tok = strtok(buff, delt);
	while (tok)
	{
		toks[jb] = strdup(tok);
		if (toks[jb] == NULL)
		{
			perror("strdupErr");
			exit(EXIT_FAILURE);
		}

		tok = strtok(NULL, delt);
		jb++;
	}

	toks[jb] = NULL;

	return (toks);
}

/**
 * read_user_input - read user input
 * @command: user input.
 * Return: NUll.
 *
 */

char *read_user_input(char *command)
{
	char *dir = find_environment("PATH");
	char *tok;
	char *full_command;
	struct stat st;

	tok = strtok(dir, ":");
	while (tok)
	{
		full_command = malloc(strlen(tok) + strlen(command) + 2);
		if (full_command == NULL)
		{
			perror("mallocError");
			exit(EXIT_FAILURE);
		}
		strcpy(full_command, tok);
		strcat(full_command, "/");
		strcat(full_command, command);
		if (stat(full_command, &st) == 0)
		{
			return (full_command);
		}
		free(full_command);
		tok = strtok(NULL, ":");
	}

	return (NULL);
}
