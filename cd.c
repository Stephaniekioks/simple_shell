#include "main.h"

void change_directory(char* directory)
{
	char *home;
	int state;
	char *prev;
	char cwd[120];


	home = getenv("HOME");
	prev = getenv("OLDPWD");
	getcwd(cwd, sizeof(cwd));

	if (directory == NULL)
	{
		state = chdir(home);
	}

	else if (strcmp(directory, "-") == 0)
	{
		state = chdir(prev);
	}

	else
	{
		state = chdir(directory);
	}

	if (state == 0)
	{
		state = chdir(directory);
	}

	if (state == 0)
	{
		setenv("PWD", cwd, 1);
	}
}
