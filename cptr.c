#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EXITCODEMSG() {
  printf("Please make sure you're entering the proper values.\n");
  return 1;
}

int main(int argc, char *argv[]) {
  int def;

  if (argc > 2 || atoi(argv[argc - 1]) > 5 || atoi(argv[argc - 1]) < 1) {
    printf("%s", "Please only provide one argument int from 1-5\n");
    exit(1);
  } else if (argc == 0)
    def = 5;
  else
    def = atoi(argv[argc - 1]);

  for (int i = 0; i < def; ++i) {
    /* Required variables */
    char ch;
    char phrase[50];
    int num;
    float num2;

    char *pphrase;
    char *pch;
    int *pnum;
    float *pnum2;

    printf("Enter a phrase: ");
    if (scanf(" %[^\n]", phrase) != 1)
      exit(EXITCODEMSG());

    printf("Enter a single character: ");
    if (scanf(" %c", &ch) != 1)
      exit(EXITCODEMSG());

    printf("Enter a single integer: ");
    if (scanf(" %d", &num) != 1)
      exit(EXITCODEMSG());

    printf("Enter a single floating point number: ");
    if (scanf(" %f", &num2) != 1)
      exit(EXITCODEMSG());

    printf("\n********* Uninitialized Pointers ***********\n");
    printf("Single character: %p\nInteger: %p\nPhrase: %p\nFloat: %p\n", pch,
           pnum, pphrase, pnum);

    /* Point the pointers to variables */
    pphrase = phrase;
    pch = &ch;
    pnum = &num;
    pnum2 = &num2;

    printf("\n********* After initialization ***********\n");
    printf("Single character: %c\nInteger: %d\nPhrase: %s\nFloat: %f\n", *pch,
           *pnum, pphrase, *pnum2);

    printf("\n********* Addresses ***********\n");
    printf("Single character: %p\nInteger: %p\nPhrase: %p\nFloat: "
           "%p\n\n***************************\n",
           &pch, &pnum, &pphrase, &pnum2);
  }

  return 0;
}
