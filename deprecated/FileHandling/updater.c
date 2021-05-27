#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;
  char *filename = NULL;
  int f;

  while ((opt = getopt(argc, argv, "f:")) != -1) {
    switch (opt) {
    case 'f':
      f = 1;
      filename = optarg;
      break;

    default:
      printf("\nUsage: [-f filename] text-to-write\n");
      exit(1);
      break;
    }
  }

  if (argc - optind != 5) {
    printf("\nMake sure your argument string is 5 words long.\n");
    printf("Usage: [-f filename] text-to-write\n");
    exit(1);
  }

  /* Get the text to write */
  char text[80];
  for (unsigned int i = optind; i < argc; i++)
    strcat(strcat(text, argv[i]), " ");

  /* If the f flag was used, open a file in append mode and write to it */
  if (f) {
    FILE *f;
    f = fopen(filename, "a");
    fprintf(f, "%s\n", text);
    fflush(f);
    fclose(f);
  } else { // Else, throw an error
    printf("\nYou need to provide a file name.\n");
    exit(1);
  }
}
