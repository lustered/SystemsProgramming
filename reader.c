#include <stdio.h>
#include <stdlib.h>
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
      printf("\nUsage: [-f filename] lines\n");
      exit(1);
      break;
    }
  }

  if(atoi(argv[argc - 1]) < 1 || atoi(argv[argc - 1]) > 10)
    printf("Please make sure you enter a number of lines 1-10.\n");

  /* If the f flag was used, open a file in append mode and write to it */
  if (f) {
    FILE *file;
    file = fopen(filename, "r");

    /* String to hold the current line */
    char cl[50];
    /* Count of the current line */
    int count = 0;
    if (access(filename, F_OK) == 0)
      while (fgets(cl, 50, file) && count < atoi(argv[argc - 1])) {
        count++;

        /* Holds 5 words with 30 characters each. */
        char words[5][30];
        sscanf(cl, "%s %s %s %s %s", words[0], words[1], words[2], words[3],
               words[4]);

        /* Iterate over the 5 words in the strings array and print them. */
        for (int i = 0; i < 5; ++i)
          printf("[%s] Sentence %d word %d = %s\n", filename, count, i,
                 words[i]);

        printf("\n");
      }
    else {
      printf("Make sure the file name you provided already exists.\n");
      exit(1);
    }

    fclose(file);
  } 
}
