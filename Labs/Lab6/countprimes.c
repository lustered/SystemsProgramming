/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/*
 * This MPI (Message Passing Interface) program computes the prime numbers in
 * in the total range of 1000000 integers. Each process has its own share of
 * calculations. The total execution time is shown by the master process.
 */

#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

#define MASTER 0
#define RANGE 1000000

int isPrime(int num) {
  // Check if num < 2 or even
  if (num <= 1 || (num % 2 == 0 && num > 2))
    return 0;

  // Check the number against its possible primes
  for (int i = 3; i < num / 2; i += 2)
    if (num % i == 0)
      return 0;

  return 1;
}

int main(int argc, char *argv[]) {
  int i, id, pNo;            // iter, process rank and No. processes
  double elapsed_time = 0;   // Calculate local execution time
  double total_elapsed_time; // Calculate total execution time
  int count = 0;             // Local primes count
  int totalprimes = 0;       // Global primes count
  char hostname[1024];       // System's hostname
  int min, max;              // Chunk/range of ints to compute

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &pNo);
  MPI_Barrier(MPI_COMM_WORLD);

  hostname[1023] = '\0';
  gethostname(hostname, 1023);

  if (id != 0) {
    // Calculate each process' load
    int chunk = RANGE / pNo;
    min = (id == 1) ? 2 : chunk * (id - 1);
    max = (id == pNo - 1) ? RANGE : id * chunk - 1;

    // ********************* START calculating time *********************
    elapsed_time = -MPI_Wtime();

    // Calculate primes
    for (i = min; i <= max; i++)
      count += isPrime(i);

    elapsed_time += MPI_Wtime();
    // ********************* STOP calculating time *********************

    printf("[%d][%s] Found %d primes between: ", id, hostname, count);
    printf("[%d - %d] in %8.6f seconds\n", min, max, elapsed_time);
    fflush(stdout);
  }

  // Add count to totalprimes in master
  MPI_Reduce(&count, &totalprimes, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);

  // Add the elapsed time to the total in master
  MPI_Reduce(&elapsed_time, &total_elapsed_time, 1, MPI_DOUBLE, MPI_SUM, MASTER,
             MPI_COMM_WORLD);

  MPI_Finalize();

  if (!id) {
    printf("There are %d different solutions\n", totalprimes);
    printf("Execution time %8.6f\n", total_elapsed_time);
    fflush(stdout);
  }

  return 0;
}
