#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t pid;
  int status;

  for (int i = 0; i < 2; i++) {
    /* Check for child */
    if ((pid = fork()) == 0) {
      /* call ls -l for the first child */
      if (i == 0) {
        system("ls -l");
        exit(0);
      }
      /* call cat folkchildren2.c for the second child */
      else {
        system("cat forkchildren2.c");
        exit(0);
      }
    } else {
      waitpid(pid, &status, 0);
      printf("Children [%d] exiting.\n\n", pid);
    }
  }

  return 0;
}
