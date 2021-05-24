/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program counts the number of words or substrings in a file.
 * Usage: mywords [-c] [-s substring] filename
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Size of the text in the file
#define FILEBUFSIZE 1000
// Size of the text for the file name and substring
#define ARGBUFSIZE 200

// Set delimeters to split the text file's line into words.
const char *delimeters[1] = {"\"\n'.,!/ "};

int main(int argc, char *argv[]) {
  int opt;
  // Count argument.
  bool copt = false;

  // Number of words or substrings in the file.
  int literalCount = 0;
  int substringCount = 0;

  char filename[ARGBUFSIZE];
  char substring[ARGBUFSIZE];

  // Get filename
  strcpy(filename, argv[argc - 1]);

  // Iterate over the params using getopt.
  while ((opt = getopt(argc, argv, "cs:")) != -1) {
    // Check param.
    switch (opt) {
    // Mark count flag.
    case 'c':
      copt = true;
      break;
    // Mark substring flag.
    case 's':
      strcpy(substring, argv[optind - 1]);
      // for (int i = optind - 1; i < argc - 1; i++)
      //   strcat(strcat(substring, argv[i]), " ");
      break;
    default:
      // Default usage.
      printf("\nUsage: mywords {optional [-c]} {optional [-s substring]} "
             "filename\n");
      exit(1);
      break;
    }
  }

  // Create a pointer to a file.
  FILE *fileob = fopen(filename, "r");
  // String to store each line from the file
  char line[FILEBUFSIZE];

  if (fileob)
    while (fgets(line, FILEBUFSIZE, fileob) != NULL) {
      char *word = strtok(line, *delimeters);
      // Split words.
      while (word != NULL) {
        // Check for equal strings
        if (strcmp(word, substring) == 0)
          literalCount++;
        if(strstr(word ,substring))
          substringCount++;


        word = strtok(NULL, *delimeters);
      }
    }
  else {
    printf("The file you have specified does not exist.\n");
    exit(1);
  }

  // Remove trailing newline added by fgets.
  // strtok(line, "\n");

  // printf("Name: %s\n", filename);
  // printf("Substring: %s\n", substring);

  // for(int i = 0; i < strlen(line); i++)
  // {
  // printf("%s", &line[0]);
  // }

  // printf("word: %s", &line[3]);
  printf("Literal matches count: %d\n", literalCount);
  printf("Substring matches count: %d\n", substringCount);

  return 0;
}
