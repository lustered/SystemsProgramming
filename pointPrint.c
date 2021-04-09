#include <stdio.h>
void printPointers(char **sentence, int *num, char *c) {
  for (; *num != 0; (*num)--)
    printf("\nNumber: %d\nInitial: %c\nSentence: %s\n", *num,
           sentence[*num - 1][0], sentence[*num - 1]);
}
