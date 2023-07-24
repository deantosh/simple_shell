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

/*Global veriable*/
extern char **environ;

/*MACROS*/
#define PROMPT "#cisfun$"

/*command struct*/
/**
 * struct builtin_command - Creates a type for the command and
 *                              its corresponding function.
 * @name: A pointer to the command name.
 * @func: A function pointer to its corresponding pointer.
 *
 * Description: struct for builtin commands.
 */
typedef struct builtin_command
{
	char *name;
	int (*func)(char **);
} builtin_s; 

/*file: main.c*/
int get_token(char *str, const char *delim);
char **create_av(char *str, int tokens, const char *delim);

/*file: parser.c*/
int command_parser(char **argv);

/*file: execute_command.c*/
int execute_builtin_command(char **argv);
int get_builtin_len(builtin_s cmd_list[]);
int execute_external_command(char **argv);

/*file: get_executable_path.c*/
char *get_full_path(char *command);
char *create_path(char *token, char *command);

/*file: memory.c*/
void free_pp(char **pp);

/*file custom_getline.c*/
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

/*Helper function for custom_getline.c File*/
void ret_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t read_input(char **input, FILE *stream);

/*BUILTIN COMMANDS*/

/*file: exit.c*/
int exit_shell(char **argv);

/*file: env.c*/
int print_env(char **argv);

/*file: change_directory.c*/
int change_directory(const char *path);

/*helper function for change_directory.c*/
void get_pwd_env(void);

/*file: helper_functions.c*/
char *_strtok(char *src, const char *delim);
int is_delim(char ch, const char *delim);
int _strlen(char *str);

#endif /*MAIN_H*/