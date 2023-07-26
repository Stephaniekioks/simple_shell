#include "main.h"

/**
 * diff_exec - handle or operator
 * @str: input
 * Return: nothing
 */
void diff_exec(char *str)
{
        char *comm;
        char *end;

        comm = my_strtok(str, "||");

        while (comm != NULL)
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
                execute_command(comm);

                comm = my_strtok(NULL, "||");
        }
}

