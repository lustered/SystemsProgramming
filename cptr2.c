#include "pointPrint.c"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  /* All the checks:
   * Less than 2 args provided.
   * Int passed < 1 or > 3.
   * The amount of string args passed matches the int
   * */
  if (argc < 3 || atoi(argv[1]) < 1 || atoi(argv[1]) > 3 ||
      atoi(argv[1]) > 1 && argc - 2 != atoi(argv[1])) {
    printf("\nPlease provide one argument int from 1-3 and an equal amount "
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
  char **pSentence;

  /* Allocate memory */
  sentence = malloc(num * 30);
  /* Get the sentence(s) */

  if (num == 1) {
    /* This is check necessary since the example in the document does not have
     * quotation marks. This way it'll grab the entire string with or without
     * quotation marks from argv. */
    char tmp[40];
    char sep = ' ';
    for (int i = 2; i < argc; i++)
      strcat(strcat(tmp, argv[i]), &sep);

    sentence[0] = tmp;
  } else
    for (int i = 0; i < argc; i++)
      sentence[i] = argv[i + 2];

  /* Assign the initial character */
  initial = sentence[0][0];

  pNum = &num;
  pInit = &initial;
  pSentence = sentence;

  /* Print all the data */
  printPointers(pSentence, pNum, pInit);

  return 0;
}
