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
  pid_t pid;
  int fd[2];
  int sfd[2];
  int status = 0;

  static char *commands[2][2] = {{"sort", "Makefile"}, {"grep", "main"}};

  pipe(fd);

  for (int i = 0; i < 3; ++i) {
    if ((pid = fork()) == 0) {
      // TESTING
      // Sort
      if(i == 0){
        close(fd[FD_READ]); // Don't need to read
        dup2(fd[FD_WRITE], 1); // Write to fd
        close(fd[FD_WRITE]); // Close
      }

      // Grep
      if(i == 1){
        pipe(sfd);

        close(sfd[FD_WRITE]);
        close(0);
        dup2(fd[FD_READ], 1);
        close(fd[FD_READ]);
      }

      // Execution code
      // execlp("sort", "sort", "counter.c", NULL);
      if (i == 2)
        execlp("wc", "wc", NULL);
      else
        execlp(commands[i][0], commands[i][0], commands[i][1], NULL);
      printf("testing\n");

      exit(0);
    }
    else if (pid == -1) {
      perror("fork failed");
      exit(-1);
    } 
    else if (pid > 0) {
      waitpid(pid, &status, 0);
      close(fd[FD_WRITE]);

      char readbuffer[1024];
      while (read(fd[0], readbuffer, sizeof(readbuffer) != 0))
        printf("%s", readbuffer);

      close(fd[FD_READ]);

      printf("CHILD #:%d || ID: [%d] DONE.\n", i+1, pid);
    }
  }

  // char readbuffer[1024];
  // while (read(fd[0], readbuffer, sizeof(readbuffer) != 0)) {
  //   printf("%s", readbuffer);
  // }

  return 0;
}
