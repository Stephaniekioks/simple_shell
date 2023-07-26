#include "main.h"
/**
 * execute_command - execute the command
 * @command: input
 * Return: nothing
 */
void execute_command(char *command)
{
        pid_t pid = fork();
        int status;

        if (strncmp(command, "exit", 4) == 0)
        {
                const char *arg = command + 4;

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
                char *token = strtok(command, " ");
                int i = 0;

                while (token != NULL && i < MAX_COMMAND_LENGTH)
                {
                        args[i] = token;
                        token = strtok(NULL, " ");
                        i++;
                }
                args[i] = NULL;
                if (execvp(args[0], args) == -1)
                {
                        fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
                        exit(1);
                }
        }
        else
        {
                wait(&status);
        }
}

