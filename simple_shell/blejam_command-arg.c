#include "blejam.h"

/**
 * command_with_args - this is function that handle command line with argument.
 * @command: this is user input.
 * @args: this is the argument pass by the user.
 */

void command_with_args(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("err");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
