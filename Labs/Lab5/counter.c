/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program will spawn three processes in total to execute the following
 * unix command equivalent: sort counter.c | grep main | wc
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define FD_READ 0
#define FD_WRITE 1

int main() {
  int sortPipe[2], grepPipe[2]; // Declare two buffers to use as fd.
  pid_t pid;                    // id for child processes.

  // List of commands to run.
  static char *commands[3][3] = {{"/bin/sort", "sort", "counter.c"},
                                 {"/usr/bin/grep", "grep", "main"},
                                 {"/usr/bin/wc", "wc", ""}};

  pipe(sortPipe); // Create the first pipe.

  // Get stdout of sort
  if ((pid = fork()) == 0) {
    // Only need to write to the pipe.
    dup2(sortPipe[FD_WRITE], FD_WRITE);

    // Execute sort counter.c
    execlp(commands[0][0], commands[0][1], commands[0][2], NULL);

    exit(0); // Close process.
  }

  // Don't need to write to this pipe anymore.
  close(sortPipe[FD_WRITE]);

  // Start another pipe to carry the stdout from grep
  pipe(grepPipe);

  // Get stdout from sort and grep main
  if ((pid = fork()) == 0) {
    // Read from the sort pipe
    dup2(sortPipe[FD_READ], FD_READ);

    // Then write the output to a new pipe
    dup2(grepPipe[FD_WRITE], FD_WRITE);

    // Execute grep main
    execlp(commands[1][0], commands[1][1], commands[1][2], NULL);

    exit(0); // Close process.
  }

  // Don't need to write to these pipes anymore.
  close(sortPipe[FD_READ]);
  close(grepPipe[FD_WRITE]);

  // Execute wc which will take the output of grep as stdin
  if ((pid = fork()) == 0) {
    // Use grep's stdout as stdin
    dup2(grepPipe[FD_READ], FD_READ);

    // execute wc {grep's output}
    execlp(commands[2][0], commands[2][1], NULL);

    exit(0); // Close process.
  }

  return 0;
}
