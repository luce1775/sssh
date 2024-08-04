#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Function declarations
void shell_loop();
char *read_line();
char **split_line(char *line);
int exec_cmd(char **args);
int shell_cd(char **args);
int shell_mkdir(char **args);
int shell_cat(char **args);
int shell_touch(char **args);
int shell_ls(char **args);
int shell_pwd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

typedef struct {
    char *name;
    int (*func)(char **args);
} command_t;

extern command_t commands[];
extern int num_commands;

#endif
