/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program calculates a salary based on parsed parameters.
 * Usage example: salary [-b num] [-r num] [-v] base
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int EXIT_MSG() {
  // Subroutine to output usage.
  printf("\nUsage: salary [-b num] [-r num] [-v] base\n");
  printf("Option base has to be in the range: 20000 <= base <= 60000\n");
  printf("Option [-b] has to be in the range: 1000 <= b <= 10000\n");
  printf("Option [-r] has to be in the range: 1 <= r <= 10\n");
  return 1;
}

int main(int argc, char *argv[]) {
  int opt;
  int bopt = 0, ropt = 0, vopt = 0;

  // Declare variables
  double base = 0;

  // Check if the base is within limit.
  if (atoi(argv[argc - 1]) < 20000 || atoi(argv[argc - 1]) > 60000)
    exit(EXIT_MSG());
  else // Grab the value
    base = atoi(argv[argc - 1]);

  // Iterate over the params using getopt.
  while ((opt = getopt(argc, argv, "b:r:v")) != -1) {
    // Check param.
    switch (opt) {
    case 'b':
      // Check for boundaries.
      if (atoi(optarg) < 1000 || atoi(optarg) > 10000) {
        // Display error and exit.
        printf("Error: Wrong value for option [-b]\n");
        exit(EXIT_MSG());
      }

      // Otherwise, grab the arg value.
      bopt = atoi(optarg);

      break;
    case 'r':
      // Check for boundaries.
      if (atoi(optarg) < 1 || atoi(optarg) > 10) {
        // Display error and exit.
        printf("Error: Wrong value for option [-r]\n");
        exit(EXIT_MSG());
      }

      // Otherwise, grab the arg value.
      ropt = atoi(optarg);

      break;
    case 'v':
      // Option [-v] was used.
      vopt = 1;
      break;
    case '?':
    default:
      // Default usage.
      fprintf(stderr, "Wrong flag passed.\n");
      exit(EXIT_MSG());
    }
  }

  // Apply veteran bonus if v flag was passed.
  base += (vopt) ? 5000 : 0;

  // Apply percentage if r flag was passed.
  base += (ropt) ? base * (ropt / 100.0) : 0;

  // Apply bonus if b flag was passed.
  base += (bopt) ? bopt : 0;

  // Display salary.
  printf("Salary: $%.2lf\n", base);

  return 0;
}
