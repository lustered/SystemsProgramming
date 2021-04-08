#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EXITCODEMSG() {
  printf("Please make sure you're entering the proper values.\n");
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc < 3 || atoi(argv[1]) < 1 || atoi(argv[1]) > 3 )
    if(atoi(argv[1]) > 1 && argc - 2 != atoi(argv[1])) {
      printf("%s", "Please provide one argument int from 1-3 and an equal amount "
                 "of strings.\n");
    exit(1);
  }

  /* Required variables */
  int num = atoi(argv[1]);
  char initial;
  char **sentence;

  /* Define pointers */
  int *pNum;
  char *pInit;
  char *pSentence;

  /* Allocate memory */
  sentence = malloc(num * 30);
  /* Get the sentence(s) */
  for (int i = 0, j = 0; i < argc; i++, ++j)
    sentence[i] = argv[i + 2];

  /* Assign the initial character */
  initial = sentence[0][0];

  pNum = &num;
  pInit = &initial;
  pSentence = *sentence;

  printf("Number: %d\nInitial: %c\nSentence: %s\n", *pNum, *pInit, pSentence);

  return 0;
}
