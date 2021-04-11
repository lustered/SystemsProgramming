#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
  char ch;
  char *stringp;
  int inum;
  float fnum;
};

typedef struct info info;

void printInfo(info *data, unsigned int const id, int onlyPt) {
  printf("**************************************\n");
  printf("Structure #%d\nString  pointer: %p\n", id, &data->stringp);

  if (!onlyPt) {
    printf("Char %c\n", data->ch);
    printf("String %s\n", data->stringp);
    printf("Int %.d\n", data->inum);
    printf("Float %.4f\n", data->fnum);
  }
}

void getInfo(info *ptr) {
  printf("Please provide the following information please.\n");
  for (int i = 0; i < 5; ++i) {
    /* Allocate 30 chars size to the string */
    ptr[i].stringp = (char *)malloc(sizeof(char) * 30);

    printf("\nEnter a string: ");
    scanf(" %[^\n]", ptr[i].stringp);

    printf("Enter a single character: ");
    scanf(" %c", &ptr[i].ch);

    printf("Enter an int number: ");
    scanf("%d", &ptr[i].inum);

    printf("Enter a float number: ");
    scanf("%f", &ptr[i].fnum);
  }
}

int main() {
  info *data = (info *)malloc(sizeof(info) * 5);

  info *s1 = &data[0], *s2 = &data[1], *s3 = &data[2], *s4 = &data[3],
       *s5 = &data[4];

  /* Fill up info structs */
  getInfo(data);

  /* Print all the values */
  unsigned int id = 1;
  printInfo(s1, id++, 0);
  printInfo(s2, id++, 0);
  printInfo(s3, id++, 0);
  printInfo(s4, id++, 0);
  printInfo(s5, id++, 0);

  /* Free the string pointer's memory */
  for (unsigned int i = 0; i < 5; ++i)
    free(data[i].stringp);

  printf("\nAfter free the malloc - the string pointers are: \n");

  id = 1;
  printInfo(s1, id++, 1);
  printInfo(s2, id++, 1);
  printInfo(s3, id++, 1);
  printInfo(s4, id++, 1);
  printInfo(s5, id++, 1);

  free(data);

  return 0;
}
