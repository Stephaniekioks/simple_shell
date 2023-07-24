#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - core of the shell
 * argc: number of arguments
 * argv: array of inputs
 * Return: integer
 */
int main(int argc, char *argv[])
{
	char command[MAX_COMMAND_LENGTH];
	char *token;
	char *end;

	if (argc > 1)
	{
		int i = 0;

		for (i = 0; i < argc; i++)
		{
			execute_command(argv[i]);
		}
	}
	else
	{
		while(1)
		{
			if (isatty(fileno(stdin)))
				display_prompt();
			read_command(command);
			if (strstr(command, "||"))
			{
				diff_exec(command);
				continue;
			}
			if (strstr(command, "&&"))
			{
				new_exec(command);
				continue;
			}
			if (strcmp(command, "exit") == 0 || feof(stdin))
			{
				break;
			}
			if (strstr(command, "cd"))
			{
				change_directory(argv[1]);
				continue;
			}
			token = my_strtok(command, ";");
			while (token != NULL)
			{
				char *single_command = token;

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
				if (strlen(single_command) > 0)
				{
					execute_command(single_command);
				}
				token = my_strtok(NULL, ";");
			}
		}
	}
	return (0);
}
