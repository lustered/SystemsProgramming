/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define FD_READ 0
#define FD_WRITE 1

int main() {
  int pipe_A[2], pipe_B[2];
  pid_t pid;

  static char *commands[3][3] = {{"/bin/sort", "sort", "counter.c"},
                                 {"/usr/bin/grep", "grep", "main"},
                                 {"/usr/bin/wc", "wc", ""}};

  pipe(pipe_A);

  if ((pid = fork()) == 0) {
    close(pipe_A[FD_READ]); // A-read not needed here

    dup2(pipe_A[FD_WRITE], FD_WRITE);
    close(pipe_A[FD_WRITE]); // do not pass A-write twice

    execlp(commands[0][0], commands[0][1], commands[0][2], NULL);

    exit(0);
  }

  close(pipe_A[FD_WRITE]); // A-write not needed anymore

  pipe(pipe_B); // do not create this pipe until needed

  if ((pid = fork()) == 0) {
    close(pipe_B[FD_READ]); // B-read not needed here

    dup2(pipe_A[FD_READ], FD_READ);
    close(pipe_A[FD_READ]); // do not pass A-read twice

    dup2(pipe_B[FD_WRITE], FD_WRITE);
    close(pipe_B[FD_WRITE]); // do not pass B-write twice

    execlp(commands[1][0], commands[1][1], commands[1][2], NULL);

    exit(0);
  }

  close(pipe_A[FD_READ]);
  close(pipe_B[FD_WRITE]);

  if ((pid = fork()) == 0) {

    dup2(pipe_B[FD_READ], FD_READ);
    close(pipe_B[FD_READ]); // do not pass B-read twice

    execlp(commands[2][0], commands[2][1], NULL);

    exit(0);
  }

  // Don't need to read from B anymore
  close(pipe_B[FD_READ]);

  return 0;
}
