#include "shell.h"

int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
    return 1;
}

int shell_mkdir(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "expected argument to \"mkdir\"\n");
    } else {
        if (mkdir(args[1], 0755) != 0) {
            perror("mkdir");
        }
    }
    return 1;
}

int shell_cat(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "expected argument to \"cat\"\n");
    } else {
        FILE *file = fopen(args[1], "r");
        if (file == NULL) {
            perror("cat");
        } else {
            char c;
            while ((c = fgetc(file)) != EOF) {
                putchar(c);
            }
            fclose(file);
        }
    }
    return 1;
}

int shell_touch(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "expected argument to \"touch\"\n");
    } else {
        FILE *file = fopen(args[1], "a");
        if (file != NULL) {
            fclose(file);
        } else {
            perror("touch");
        }
    }
    return 1;
}

int shell_ls(char **args) {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("ls");
    }
    return 1;
}

int shell_pwd(char **args) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("pwd");
    }
    return 1;
}

int shell_help(char **args) {
    printf("Available commands:\n");
    for (int i = 0; i < num_commands; i++) {
        printf("  %s\n", commands[i].name);
    }
    return 1;
}

int shell_exit(char **args) {
    return 0;
}
