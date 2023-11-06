#include "blejam.h"

/**
 * main - the main function
 * Return: 0.
 *
 */


int main(void)
{
	char **myenv = environ;
	char *buff = NULL;
	char **args;
	size_t buff_size = 0;
	char *input;
	pid_t pid;
	int numChar, progress;

	while (1)
	{
		write(1, "#blejam& ", 9);
		numChar = getline(&buff, &buff_size, stdin);
		if (numChar == -1)
		{
			write(1, "\n", 1);
			exit(1);
		}
		args = tokenilize(buff, " \t\n");
		/*if (strcmp(args[0], "exit") == 0)
			exit(0);*/
		pid = fork();
		if (pid == 0)
		{
			input = read_user_input(args[0]);
			if (input)
				execve(input, args, myenv);
			else
				printf("command not found\n");
			exit(0);
		}
		else
			wait(&progress);
	}
	return (0);
}
