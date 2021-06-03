/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program counts the number of words and/or substrings in a file.
 * Usage: mywords [-c] [-s substring] filename
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILEBUFSIZE 1000 // Size allowed for each line.
#define ARGBUFSIZE 200   // Size of the text for the file name and substring

// Set delimeters to split the text file's line into words.
const char *delimeters[] = {"\"\n.,!/ "};

int main(int argc, char *argv[]) {
  int opt;
  // Arguments checks.
  bool copt = false;
  bool sopt = false;

  // Number of words or substrings in the file.
  int wordCount = 0;
  int substringCount = 0;

  // Declare strings for the file and substring.
  char filename[ARGBUFSIZE];
  char substring[ARGBUFSIZE];

  const char usage[100] = {"\nUsage: mywords [-c] [-s substring] filename\n"};

  // Iterate over the params using getopt.
  while ((opt = getopt(argc, argv, "cs:")) != -1) {
    switch (opt) { // Check param.
    case 'c':      // Mark count flag.
      copt = true;

      break;
    case 's': // Mark substring flag.
      if (optind >= argc) {
        printf("Make sure you have supplied a substring and a filename\n");
        fprintf(stderr, usage);
        exit(1);
      }
      sopt = true;
      strcpy(substring, argv[optind - 1]);

      break;
    default: // Default usage.
      fprintf(stderr, usage);
      exit(1);
      break;
    }
  }

  // Check if there was a filename arg.
  if (optind >= argc) {
    printf("Please make sure you have supplied a filename\n");
    fprintf(stderr, usage);
    exit(1);
  }

  // Get filename
  strcpy(filename, argv[argc - 1]);

  // Make sure an operation is needed.
  if (copt || sopt) {
    if (access(filename, F_OK) == 0) {
      // Create a pointer to a file.
      FILE *fileob = fopen(filename, "r");

      // String to store each line from the file
      char line[FILEBUFSIZE];

      // Iterate over every line in the file
      while (fgets(line, FILEBUFSIZE, fileob) != NULL) {
        // Extract word given the delimeters.
        char *word = strtok(line, *delimeters);

        // Count words
        while (word != NULL) {
          // printf("Word: %s\n", word);

          // Increase word count.
          wordCount++;

          // Check for substring.
          if (strstr(word, substring))
            substringCount++;

          // Move onto the next word.
          word = strtok(NULL, *delimeters);

        } // end while
      }   // end while
    }     // end if
    else {
      printf("The file you have specified does not exist.\n");
      exit(1);
    }
  } // end outer if

  // Display information.
  printf("File name: %s\n", filename);

  if (copt)
    printf("Words count: %d\n", wordCount);

  if (sopt)
    printf("Substring: %s\nMatches: %d\n", substring, substringCount);

  return 0;
}
