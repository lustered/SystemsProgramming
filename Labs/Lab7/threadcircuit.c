#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

/* Return 1 if 'i'th bit of 'n' is 1; 0 otherwise */
#define EXTRACT_BIT(n, i) ((n & (1 << i)) ? 1 : 0)
#define THREADNUM 8

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  int *count;
} thread_data_t;

/* shared data between threads */
double shared_x;
pthread_mutex_t lock_x;

int check_circuit(int z) {
  int v[16]; /* Each element is a bit of z */
  int i;

  for (i = 0; i < 16; i++)
    v[i] = EXTRACT_BIT(z, i);
  if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3]) &&
      (!v[3] || !v[4]) && (v[4] || !v[5]) && (v[5] || !v[6]) &&
      (v[5] || v[6]) && (v[6] || !v[15]) && (v[7] || !v[8]) &&
      (!v[7] || !v[13]) && (v[8] || v[9]) && (v[8] || !v[9]) &&
      (!v[9] || !v[10]) && (v[9] || v[11]) && (v[10] || v[11]) &&
      (v[12] || v[13]) && (v[13] || !v[14]) && (v[14] || v[15])) {
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", v[0], v[1], v[2], v[3], v[4],
           v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14],
           v[15]);
    return 1;
  } else
    return 0;
}

void *runthread(void *arg){
  thread_data_t *data = (thread_data_t *)arg;
  int *cptr, localcount = 0;
  cptr = data->count;

  /* get mutex before modifying and printing shared_x */
  // ******************** MODIFYING ********************

  printf("Hello from %d\n", data->tid);
  // TODO
  // int min = (data->tid % 2)
  // for (int i = 0; i < )
    // count += check_circuit(i);
  for(int i = data->tid; i < 65636; i += THREADNUM)
    localcount += check_circuit(i);

  // ******************** END MODIFYING ****************

  pthread_mutex_lock(&lock_x);
  data->count += localcount;
  pthread_mutex_unlock(&lock_x);

  pthread_exit(NULL);

}

int main(int argc, char *argv[]) {
  int count, i, rc;

  pthread_t thr[THREADNUM];
  /* create a thread_data_t argument array */
  thread_data_t thr_data[THREADNUM];

  /* initialize shared data */
  shared_x = 0;

  /* initialize pthread mutex protecting "shared_x" */
  pthread_mutex_init(&lock_x, NULL);

  for (i = 0; i < THREADNUM; ++i) {
    thr_data[i].tid = i;
    thr_data[i].count = &count;

    if ((rc = pthread_create(&thr[i], NULL, runthread, &thr_data[i]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return -1;
    }
  }

  /* block until all threads complete */
  for (i = 0; i < THREADNUM; ++i) {
    pthread_join(thr[i], NULL);
  }

  printf("There are %d solutions\n", count);
  return 0;
}
