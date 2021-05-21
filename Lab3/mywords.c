/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program counts the number of words or substrings in a file.
 * Usage: mywords [-c] [-s substring] filename
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;
  // Number of words or substrings in the file.
  int count;
  char filename[50];
  strcpy(filename, argv[argc - 1]);

  // Iterate over the params using getopt.
  while ((opt = getopt(argc, argv, "cs")) != -1) {
    // Check param.
    switch (opt) {
    case 'c':
      // TODO
      break;
    case 's':
      // TODO
      break;
    default:
      // Default usage.
      printf("\nUsage: mywords {optional [-c]} {optional [-s substring]} "
             "filename");
      exit(1);
      break;
    }
  }

  return 0;
}
