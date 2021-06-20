/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program counts the number of words and/or substrings in a file. The
 * program must receive an existing and valid file. Any number of flags can be
 * used or none.
 *
 * Usage: mywords [-c] [-s substring] filename
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILEBUFSIZE 1000 // Size allowed for each line.
#define ARGBUFSIZE 200   // Size of the text for the file name and substring

int main(int argc, char *argv[]) {
  int opt;
  // Arguments checks.
  int copt = 0;
  int sopt = 0;

  // Number of words or substrings in the file.
  int wordCount = 0;
  int substringCount = 0;

  // Declare strings for the file and substring.
  char filename[ARGBUFSIZE];
  char substring[ARGBUFSIZE];

  // Set delimeters to split the text file's line into words.
  static char delimeters[] = {"\"\n.,!/ "};

  const char usage[100] = {"\nUsage: mywords [-c] [-s substring] filename\n"};

  // Iterate over the params using getopt.
  while ((opt = getopt(argc, argv, "cs:")) != -1) {
    switch (opt) { // Check param.
    case 'c':
      copt = 1; // Count flag.
      break;
    case 's': // Substring param.
      if (optind >= argc) {
        printf("Make sure you have supplied a substring and a filename\n");
        fprintf(stderr, usage);
        exit(1);
      }
      sopt = 1;
      strcpy(substring, argv[optind - 1]); // Grab the string
      break;
    case '?': // Invalid option passed
      printf("Invalid flag usage.\n");
      fprintf(stderr, usage);
      exit(1);
      break;
    default: // Default usage.
      fprintf(stderr, usage);
      exit(1);
      break;
    }
  }

  // Check if there was a filename arg
  if (optind >= argc) {
    printf("Please make sure you have supplied a filename\n");
    fprintf(stderr, usage);
    exit(1);
  }

  // Get filename
  strcpy(filename, argv[argc - 1]);

  FILE *fileob;
  // Check the file exists
  if (access(filename, F_OK) == 0)
    // Create a pointer to read from the file
    fileob = fopen(filename, "r");
  else { // File doesnt exist in the directory
    printf("The file you have specified does not exist.\n");
    fprintf(stderr, usage);
    exit(1);
  }

  // String to store each line from the file
  char line[FILEBUFSIZE];

  // Make sure an operation is needed.
  if (copt || sopt) {
    // Iterate over every line in the file
    while (fgets(line, FILEBUFSIZE, fileob) != NULL) {
      // Extract word given the delimeters.
      char *word = strtok(line, delimeters);

      // Count words
      while (word != NULL) {
        // printf("Word: %s\n", word);

        // Increase word count
        wordCount++;

        // Check for substring
        if (strstr(word, substring))
          substringCount++;

        // Move onto the next word
        word = strtok(NULL, delimeters);

      } // end inner while

      free(word); // Free up allocated memory

    }    // end outer while
  }      // end outer if
  else { // No options were passed. Print the entire file to stdout
    while (fgets(line, FILEBUFSIZE, fileob) != NULL)
      printf("%s", line);
  }

  fclose(fileob); // Close file pointer

  // Display information
  if (copt)
    printf("Words count: %d\n", wordCount);

  if (sopt)
    printf("Substring: %s\nMatches: %d\n", substring, substringCount);

  return 0;
}
