#include "blejam.h"

/**
 * display_command - Function to display a prompt
 * @command: This is a command variables
 * @args: argument statement
 */

void display_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/*char *args[] = {command, NULL};*/

		if (execve(command, args, NULL) == -1)
		{
			perror("err");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("err");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * get_input - Function to read a prompt
 * @line: this is the command for user input
 * @length: indicate the length of the user input
 * Return: return 0 or 1
 */

int get_input(char **line, size_t *length)
{
	size_t readline;

	printf("#blejam$ ");
	readline = getline(line, length, stdin);
	if (readline == (size_t)-1)
	{
		if (feof(stdin))
		{
			printf("\n");

			return (0);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}
	if ((*line)[readline - 1] == '\n')
	{
		(*line)[readline - 1] = '\0';
	}

	return (1);
}
