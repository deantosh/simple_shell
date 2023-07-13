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

/*file: execute_command.c*/
void execute_command(char **argv);

/*file: get_executable_path.c*/
char *get_full_path(char *command);
char *create_path(char *token, char *command);

/*file: memory.c*/
void free_pp(char **pp);

#endif /*MAIN_H*/
