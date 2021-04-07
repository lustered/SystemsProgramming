#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void uppercase(char *text) {
  /* Swap in-place every character for the uppercase version */
  char *tmp;
  tmp = strtok(text, ":");
  char *s = tmp;
  while (*s) {
    *s = toupper((unsigned char)*s);
    s++;
  }
}

void lowercase(char *text) {
  /* Swap in-place every character for the uppercase version */
  char *tmp;
  tmp = strtok(text, ":");
  char *s = tmp;
  while (*s) {
    *s = tolower((unsigned char)*s);
    s++;
  }
}

int main(int argc, char *argv[]) {
  int opt;
  char *filename = NULL;
  int l, u, f;

  while ((opt = getopt(argc, argv, "luf:")) != -1) {
    switch (opt) {
    case 'l':
      if (u == 1) {
        printf("\nPlease avoid using both -l and -u in the same command.");
        printf("\nUsage: writer [-l] lowercase or [-u] uppercase [-f filename] "
               "text-to-write\n");
        exit(1);
      }

      l = 1;
      break;

    case 'u':
      if (l == 1) {
        printf("\nPlease avoid using both -l and -u in the same command.");
        printf("\nUsage: writer [-l] lowercase or [-u] uppercase [-f filename] "
               "text-to-write\n");
        exit(1);
      }

      u = 1;
      break;

    case 'f':
      f = 1;
      filename = optarg;
      break;

    default:
      printf("\nUsage: writer [-l] lowercase or [-u] uppercase [-f filename] "
             "text-to-write\n");
      exit(1);
      break;
    }
  }

  if(argc - optind < 3 || argc - optind > 10){
    printf("Please make sure the argument string is between 3-10 words\n");
    exit(1);
  }

  /* Get the text to write */
  char text[80];
  for (unsigned int i = optind; i < argc; i++)
    strcat(strcat(text, argv[i]), " ");

  if (strlen(text) < 1) {
    printf("\nPlease enter some text to print or write to file.\n");
    printf("Usage: writer [-l] lowercase or [-u] uppercase [-f filename] "
           "text-to-write\n");
    exit(1);
  }

  if (l)
    lowercase(text);
  else if (u)
    uppercase(text);

  if (f) {
    FILE *f;
    f = fopen(filename, "w");
    fprintf(f, "Ernesto Rodriguez: %s", text);
    fflush(f);
    fclose(f);
  }

  printf("Ernesto Rodriguez: %s", text);
}
