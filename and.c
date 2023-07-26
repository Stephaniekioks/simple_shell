#include "main.h"

/**
 * new_exec - handle && operator
 * @str: string input
 * Return: nothing
 */
void new_exec(char *str)
{
	char *comm;
	char *end;
	int status;
	pid_t pid;

	comm = my_strtok(str, "&&");

	status = 0;
	while (comm != NULL && status == 0)
	{
		char *single_command = comm;

		while (*single_command == ' ')
		{
			single_command++;
		}
		end = single_command + strlen(single_command) - 1;
		while (*end == ' ' && end >= single_command)
		{
			*end = '\0';
			end--;
		}
		pid = fork();
		if (strncmp(comm, "exit", 4) == 0)
		{
			const char *arg = comm + 4;

			while (*arg == ' ')
			{
				arg++;
			}

			status = atoi(arg);
			exit(status);
		}
		if (pid < 0)
		{
			fprintf(stderr, "Fork failed.\n");
			return;
		}
		else if (pid == 0)
		{
			char *args[MAX_COMMAND_LENGTH];
			char *token = my_strtok(single_command, "");
			int i = 0;

			while (token != NULL && i < MAX_COMMAND_LENGTH)
			{
				args[i] = token;
				token = my_strtok(NULL, "");
				i++;
			}
			args[i] = NULL;
			if (strcmp(args[0], "cd") == 0)
			{
				change_directory(args[1]);
				exit(0);
			}
			if (execvp(args[0], args) == -1)
			{
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		comm = my_strtok(NULL, "&&");
	}
}
