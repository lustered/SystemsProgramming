/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/*
 * [DESCRIPTION]
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 20
#define BUFSIZE 1024
#define FDR 0
#define FDW 1
#define WRITEMODE(mode) (mode == 1 ? O_APPEND : O_TRUNC)

int get_args(char *cmdline, char *args[]) {
  int i = 0;

  // if no args
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

char *concatcmd(char *args[], int start, int end) {
  // Return a single string from an array of strings in a range
  if (end <= start) {
    fprintf(stderr, "Wrong range\n");
    exit(1);
  }

  char *ret = malloc((end - start) * 20);
  for (int i = start; i < end; i++)
    strncat(strncat(ret, args[i], sizeof(args[i]) + 1), " ", 2);

  return ret;
}

void execute(char *cmdline) {
  int pid, async = 0;
  char *newcmd = NULL;
  char *iofile = NULL;
  char *args[MAX_ARGS];
  int mode;

  int nargs = get_args(cmdline, args);

  if (nargs <= 0)
    return;

  for (int i = 0; i < nargs; i++) {
    int rf = 0; // Flag for redirect found

    // Check for >> and >
    if (!strcmp(args[i], ">>") || !strcmp(args[i], ">") && !rf) {
      rf = 1;

      // Use O_APPEND for >> and O_TRUNC for >
      mode = (!strcmp(args[i], ">>") ? 1 : 0);

      // printf("[caught redirect]\n");
      // Check for the file
      if (i < nargs - 1) {
        // Grab file to redirect to
        iofile = args[i + 1];

        // Adjust the command to properly be executed
        newcmd = concatcmd(args, 0, i);
        nargs = get_args(newcmd, args);
      }
    }
  }

  pid = fork();
  // child process
  if (pid == 0) {
    if (iofile != NULL) {
      int fd = open(iofile, O_RDWR | O_CREAT | WRITEMODE(mode), S_IRUSR | S_IWUSR);
      dup2(fd, FDW);
      close(fd);
    }

    execvp(args[0], args);

    // return only when exec fails
    perror("exec failed");
    exit(-1);
  } else if (pid > 0) { // parent process
    if (!async)
      waitpid(pid, NULL, 0);
    else
      printf("this is an async call\n");
  } else { // error occurred
    perror("fork failed");
    exit(1);
  }
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

/*
if(!strcmp(args[0], "quit") || !strcmp(args[0], "exit")) {
  exit(0);
}

// check if async call
if(!strcmp(args[nargs-1], "&")) { async = 1; args[--nargs] = 0; }
else async = 0;
*/
