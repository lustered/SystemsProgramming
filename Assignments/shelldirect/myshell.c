/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/*
 * This program will simulate a standard UNIX shell with redirection and
 * pipeline support.
 *
 * Usage: ./myshell
 *
 * Example: sort < myshell.c > output
 *
 * ** This file makes use of the provided myshell.c code sample **
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 20
#define BUFSIZE 1024

// Macro to use in open(). > (truncates) and >> (appends)
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

  int limitindex = 0; // keep track of index in arg_chunk for execvp
  int fdin, fdout;    // file descriptors for redirection

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
  int pipeargs[5] = {0}; // count of args before each pipe

  // Iterate over all the args
  for (int i = 0; i < nargs; i++, cmd++) {
    // If a pipe is found, start the next command in a new array
    if (!strcmp(args[i], "|")) {
      j++;
      i++;
      cmd = 0;
      pipecount++;
    }

    pipeargs[j]++;               // Increase the count of params up until a pipe
    parsedcmd[j][cmd] = args[i]; // Assign the proper array index and param
  }

  // Start pipe
  int pipefd[2];
  pipe(pipefd);

  char **arrptr;          // Pointer to array pointer
  int tmpcnt = pipecount; // Keep a temporary count of pipes

  // Iterate over the amount of commands
  // Each command before a pipe needs to be ran by itself. Their output is then
  // sent  to a pipe to be read by the next command's stdin
  for (int pidx = 0; pidx <= pipecount; pidx++, tmpcnt--) {
    // This array will contain the stripped down commands for execvp
    char *arg_chunk[MAX_ARGS];
    arrptr = parsedcmd[pidx]; // Use the proper command index inside the fork

    pid = fork();
    if (pid == 0) { // child process

      if (tmpcnt == 1) {        // start communicating pipes
        close(pipefd[0]);       // Don't need to read in the first pipe
        dup2(pipefd[1], 1);     // Duplicate stdin to the pipe's write
        close(pipefd[1]);       // Close the file descriptor
      } else if (tmpcnt == 0) { // Send final pipe's output to normal stdout
        dup2(pipefd[0], 0);     // Read from the pipe
        close(pipefd[0]);       // Don't need the fds again
        close(pipefd[1]);
      } else { // communicate pipes
        // This may not work and more pipes are needed to transfer the outputs
        dup2(pipefd[0], pipefd[1]); // Duplicate read and write fds
        // dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
      }

      // Iterate over the command's params
      for (int i = 0; i < pipeargs[pidx]; i++) {
        int replaced = 0;

        if (!replaced) {
          // Check for stdin
          if (!strcmp(arrptr[i], "<")) {
            replaced++;
            i++; // Skip symbol

            // Check if the file descriptor to read from works
            if ((fdin = open(arrptr[i], O_RDONLY)) < 0)
              fprintf(stderr, "Bad input file descriptor\n");

            // Use the file as input
            dup2(fdin, STDIN_FILENO);
            close(fdin); // Don't need anymore
          }

          if (!strcmp(arrptr[i], ">") || !strcmp(arrptr[i], ">>")) {
            replaced++;
            i++; // Skip symbol

            // Open the file descriptor. It will create it if doesn't exist. It
            // will use O_TRUNC if the redirect is '>' and O_APPEND for '>>'
            int fdout = open(arrptr[i],
                             O_RDWR | O_CREAT | WRITEMODE(arrptr[i - 1]), 0644);

            // Connect stdout to descriptor
            dup2(fdout, STDOUT_FILENO);
            close(fdout);
          }
        }

        // Grab the command if it wasn't a redirect symbol
        if (!replaced)
          arg_chunk[limitindex++] = arrptr[i];
      }

      // Set last command delimiter
      arg_chunk[limitindex] = NULL;

      execvp(arg_chunk[0], arg_chunk);

      // return only when exec fails
      perror("exec failed");
      exit(-1);
    } else if (pid > 0) { // parent process
      if (tmpcnt == 0)
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
  // Close pipes
  // close(pipefd[1]);
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
