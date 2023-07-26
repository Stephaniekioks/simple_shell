#include "main.h"

/**
 * custom_fgets - gets user input from stdin
 * @str: string input
 * @size: bytes of input
 * @stream: source
 * Return: characters
 */

char *custom_fgets(char *str, int size, FILE *stream)
{
        int count;
        int ch;

        if (size <= 0 || !str || !stream)
                return (NULL);
        count = 0;
        while (count < size - 1)
        {
                ch = fgetc(stream);
                if (ch == EOF)
                        break;

                str[count] = ch;
                count++;
                if (ch == '\n')
                        break;
        }
        if (count == 0)
                return (NULL);
        str[count] = '\0';

        return (str);
}
/**
 * read_command - read the user input
 * @command: character
 * Return: nothing
 */
void read_command(char *command)
{
        custom_fgets(command, MAX_COMMAND_LENGTH, stdin);

        command[strcspn(command, "\n")] = '\0';

}
