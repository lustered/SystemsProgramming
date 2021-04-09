#include <stdio.h>
int printPointers(char *sentence, int *num, char *initial) {
  printf("\nNumber: %d\nInitial: %c\nSentence: %s\n", *num, *initial, sentence);

  return (*num)--;
}
