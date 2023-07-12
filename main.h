#ifndef MAIN_H
#define MAIN_H

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/*MACROS*/
#define PROMPT "#cisfun$"

/*file: main.c*/
int get_token(char *str, const char *delim);
char **create_av(char *str, int tokens, const char *delim);

/*file: exec-system_command.c*/
void execute_system_command(char **argv);

/*file: memory.c*/
void free_pp(char **pp);

#endif /*MAIN_H*/
