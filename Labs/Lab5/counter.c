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
  int sortPipe[2], grepPipe[2];
  pid_t pid;

  static char *commands[3][3] = {{"/bin/sort", "sort", "counter.c"},
                                 {"/usr/bin/grep", "grep", "main"},
                                 {"/usr/bin/wc", "wc", ""}};

  pipe(sortPipe);
  pipe(grepPipe);

  if ((pid = fork()) == 0) {
    dup2(sortPipe[FD_WRITE], FD_WRITE);

    execlp(commands[0][0], commands[0][1], commands[0][2], NULL);

    exit(0);
  }

  // Close sort's write
  close(sortPipe[FD_WRITE]);

  if ((pid = fork()) == 0) {
    dup2(sortPipe[FD_READ], FD_READ);
    dup2(grepPipe[FD_WRITE], FD_WRITE);

    execlp(commands[1][0], commands[1][1], commands[1][2], NULL);

    exit(0);
  }

  close(sortPipe[FD_READ]);
  close(grepPipe[FD_WRITE]);

  if ((pid = fork()) == 0) {
    dup2(grepPipe[FD_READ], FD_READ);
    execlp(commands[2][0], commands[2][1], NULL);
    exit(0);
  }

  return 0;
}
