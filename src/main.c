#include "shell.h"

// Command dictionary structure
command_t commands[] = {
  {"cd", shell_cd},
  {"mkdir", shell_mkdir},
  {"cat", shell_cat},
  {"touch", shell_touch},
  {"ls", shell_ls},
  {"pwd", shell_pwd},
  {"help", shell_help},
  {"exit", shell_exit}
};

int num_commands = sizeof(commands) / sizeof(command_t);

int main() {
  shell_loop();
  return 0;
}

void shell_loop() {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = read_line();
    args = split_line(line);
    status = exec_cmd(args);

    free(line);
    free(args);
  } while (status);
}
