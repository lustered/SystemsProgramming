/* This example is stolen from Dr. Raju Rangaswami's original 4338
   demo and modified to fit into our lecture. */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 20
#define BUFSIZE 1024

#define WRITEMODE(param) (!strcmp(param, ">") ? O_TRUNC : O_APPEND)

int get_args(char *cmdline, char *args[]) {
  int i = 0;

  /* if no args */
  if ((args[0] = strtok(cmdline, "\n\t ")) == NULL)
    return 0;

  while ((args[++i] = strtok(NULL, "\n\t ")) != NULL) {
    if (i >= MAX_ARGS) {
      printf("Too many arguments!\n");
      exit(1);
    }
  }
  /* the last one is always NULL */
  return i;
}

void execute(char *cmdline) {
  int pid, async;
  char *args[MAX_ARGS];
  // This array will contain the stripped down commands for execvp
  int limitindex = 0;
  int fdin, fdout;

  char *parsedcmd[5][MAX_ARGS]; // up to 5 commands of 20 args each
  int pipecount = 0;

  int nargs = get_args(cmdline, args);
  if (nargs <= 0)
    return;

  if (!strcmp(args[0], "quit") || !strcmp(args[0], "exit")) {
    exit(0);
  }

  /* check if async call */
  if (!strcmp(args[nargs - 1], "&")) {
    async = 1;
    args[--nargs] = 0;
  } else
    async = 0;

  // Split piped command
  int j = 0;
  int cmd = 0;
  int pipeargs[5] = {0};
  for (int i = 0; i < nargs; i++, cmd++) {
    if (!strcmp(args[i], "|")) {
      j++;
      i++;
      cmd = 0;
      pipecount++;
    }
    pipeargs[j]++;
    parsedcmd[j][cmd] = args[i];
  }

  int pipefd[2];
  pipe(pipefd);
  char **arrptr;
  int tmpcnt = pipecount;

  for (int pidx = 0; pidx <= pipecount; pidx++, tmpcnt--) {
    char *arg_chunk[MAX_ARGS];
    arrptr = parsedcmd[pidx];
    // printf("arg1: %s  arg2: %s\n", arrptr[0], arrptr[1]);

    pid = fork();

    if (pid == 0) { // child process

      if (tmpcnt == 1) {
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);
      } else {
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        close(pipefd[1]);
      }

      for (int i = 0; i < pipeargs[pidx]; i++) {
        int replaced = 0;

        if (!replaced) {
          // Check for stdin
          if (!strcmp(arrptr[i], "<")) {
            replaced++;
            i++;

            // Check if the file descriptor to read from works
            if ((fdin = open(arrptr[i], O_RDONLY)) < 0)
              fprintf(stderr, "Bad input file descriptor\n");

            dup2(fdin, STDIN_FILENO); // duplicate stdin to input file
            close(fdin);              // close after use
          }

          if (!strcmp(arrptr[i], ">") || !strcmp(arrptr[i], ">>")) {
            replaced++;
            i++;

            // Open the file descriptor. It will create it if doesn't exist. It
            // will use O_TRUNC if the redirect is '>' and O_APPEND for '>>'
            int fdout = open(arrptr[i],
                             O_RDWR | O_CREAT | WRITEMODE(arrptr[i - 1]), 0644);

            // Connect stdout to descriptor
            dup2(fdout, STDOUT_FILENO);
            close(fdout);
          }
        }

        if (!replaced) {
          arg_chunk[limitindex++] = arrptr[i];
        }
      }

      // Set last command delimiter
      arg_chunk[limitindex] = NULL;

      execvp(arg_chunk[0], arg_chunk);

      // return only when exec fails
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { // parent process
      close(pipefd[1]);

      if (!async) {
        waitpid(pid, NULL, 0);

      } else
        printf("this is an async call\n");
    } else { // error occurred
      perror("fork failed");
      exit(1);
    }
  }
  close(pipefd[0]);
}

int main(int argc, char *argv[]) {
  char cmdline[BUFSIZE];

  for (;;) {
    printf("COP4338$ ");
    if (fgets(cmdline, BUFSIZE, stdin) == NULL) {
      perror("fgets failed");
      exit(1);
    }
    execute(cmdline);
  }
  return 0;
}
