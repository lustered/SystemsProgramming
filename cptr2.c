#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EXITCODEMSG() {
  printf("Please make sure you're entering the proper values.\n");
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc < 3 || atoi(argv[1]) > 3 || atoi(argv[1]) < 1) {
    printf("%s", "Please provide one argument int from 1-3 and a string.\n");
    exit(1);
  } 

  /* Required variables */
  int num = atoi(argv[1]);
  char initial;
  char *sentence = malloc(num + 1);

  /* Define pointers */
  int *pNum;
  char *pInit;
  char *pSentence;

  char space[] = " ";
  /* Get the sentence */
  for (int i = 2, j = 0; i < argc; i++, ++j)
    strcat(strcat(sentence, argv[i]), space);

  /* Assign the initial character */ 
  initial = sentence[0];

  pNum = &num;
  pInit = &initial;
  pSentence = sentence;

  /* printf("Sentence: %s\n", sentence); */
  /* printf("Initial: %c\n", initial); */

  printf("Number: %d\nInitial: %c\nSentence: %s\n", *pNum, *pInit, pSentence);

  return 0;
}
