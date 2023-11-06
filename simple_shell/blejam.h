#ifndef BLEJAM_H
#define BLEJAM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

extern char **environ;
void display_command(char *command, char *args[]);
int get_input(char **line, size_t *length);
void command_with_args(char *command, char *args[]);
char *find_environment(const char *myenv);
char **tokenilize(char *buff, char *delt);
char *read_user_input(char *command);

#endif
