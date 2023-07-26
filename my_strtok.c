#include "main.h"

/**
 * my_strtok - custom strtok function
 * @str: string to break
 * @delim: seperator
 * Return: chars
 */
char *my_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next;

	if (str != NULL)
	{
		next = str;
	}
	if (next == NULL)
	{
		return (NULL);
	}
	token = next + strspn(next, delim);
	next = strpbrk(token, delim);
	if (next != NULL)
	{
		*next = '\0';
		next++;
	}
	return (token);
}
