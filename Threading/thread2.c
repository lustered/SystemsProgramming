#include <pthread.h>
#include <stdio.h>

long sharedVal = 100;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *addVal(void *tid) {
  pthread_mutex_lock(&mutex);

  /* Print thread ID */
  printf("Thread ID: %ld\n", (long)pthread_self());

  /* Print shared val */
  /* printf("The value for the shared number is: %ld\n", sharedVal); */

  sharedVal += (long)pthread_self();

  pthread_mutex_unlock(&mutex);

  return 0;
}

int main() {
  pthread_t IDs[5];

  /* Create 5 threads */
  for (int i = 0; i < 5; i++)
    pthread_create(&IDs[i], NULL, addVal, NULL);

  /* Wait for threads to finish running */
  for (int i = 0; i < 5; i++)
    pthread_join(IDs[i], NULL);

  /* Print final value */
  printf("The value for the shared number is: %ld\n", sharedVal);

  return 0;
}
