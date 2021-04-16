#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t pid;
  int status;

  printf("Parent PID at entry is [%d]\n\n", getpid());

  /* Create 5 children */
  for (int i = 0; i < 5; i++) {
    /* Check for child */
    if ((pid = fork()) == 0) {
      /* Print child pid and message 6 times */
      for (int j = 0; j < 6; j++) {
        printf("I am child [%d] and this is message num [%d]\n", getpid(),
               j + 1);
        sleep(5);
      }
      exit(0);
    } else {
      waitpid(pid, &status, 0);
      printf("Children [%d] exiting.\n\n", pid);
    }
  }

  printf("Parent PID at entry is [%d]\n", getpid());

  return 0;
}
