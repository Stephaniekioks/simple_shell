#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
void read_command(char *command);
void display_prompt(void);
void execute_command(char *command);
int my_cd(const char *path);
char *my_strtok(char *str, const char *delim);
void change_directory(char *directory);
void diff_exec(char *str);
void new_exec(char *str);
#endif
