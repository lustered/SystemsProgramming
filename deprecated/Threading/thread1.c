#include <pthread.h>
#include <stdio.h>

long sharedVal = 100;

void *addVal(void *tid) {
  sharedVal += (long) tid;

  /* Print thread ID */
  printf("Thread ID: %ld\n", (long) pthread_self());

  /* Print shared val */
  /* printf("The value for the shared number is: %ld\n", sharedVal); */

  return 0;
}

int main() {
  pthread_t IDs[5];

  /* Create 5 threads */
  for (int i = 0; i < 5; i++)
    pthread_create(&IDs[i], NULL, addVal, &IDs[i]);

  /* Wait for threads to finish running */
  for (int i = 0; i < 5; i++)
      pthread_join(IDs[i], NULL);

  printf("The value for the shared number is: %ld\n", sharedVal);

  return 0;
}
