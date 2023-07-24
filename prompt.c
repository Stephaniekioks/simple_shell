#include "main.h"
/**
 * display_prompt - display prompt
 * Return: nothing
 */
void display_prompt(void)
{
	if ((isatty(fileno(stdout))) != 0)
	{
		const char *prompt = "$ ";
		write(1, prompt, 2);
	}
}
