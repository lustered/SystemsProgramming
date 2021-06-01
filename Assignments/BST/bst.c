/* NOTES:
 * Need to assign left/right nodes
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistdio.h>

#define BUFSIZE 100

typedef struct node {
  char *info;
  struct node *left;
  struct node *right;
} node;

node *createNode(char *info) {
  node *ret = (node *)malloc(sizeof(node));
  ret->info = info;
  ret->right = NULL;
  ret->left = NULL;

  return ret;
}

char *strLower(char *string) {
  for (char *i = string; *i; i++)
    *i = tolower(*i);

  return string;
}

int _scmpSensitive(char *string1, char *string2) {

  unsigned char *s1 = (unsigned char *)string1;
  unsigned char *s2 = (unsigned char *)string2;

  unsigned char c1, c2;

  do {
    c1 = (unsigned char)*s1++;
    c2 = (unsigned char)*s2++;
    if (c1 == '\0')
      return c1 - c2;
  } while (c1 == c2);

  return c1 - c2;
}

int _scmpInsensitive(char *string1, char *string2) {

  unsigned char *s1 = (unsigned char *)(string1);
  unsigned char *s2 = (unsigned char *)(string2);

  unsigned char c1, c2;

  do {
    c1 = (unsigned char)tolower(*s1++);
    c2 = (unsigned char)tolower(*s2++);
    if (c1 == '\0')
      return c1 - c2;
  } while (c1 == c2);

  return c1 - c2;
}

void inorderTraversal(node *n) {
  if (n == NULL)
    return;
  inorderTraversal((node *)n->left);
  printf("[NODE]%s\n", n->info);
  inorderTraversal((node *)n->right);
}

node *insertNode(node *head, char *info) {
  if (head == NULL) {
    // printf("Added node\n");
    return createNode(info);
  }

  if (_scmpSensitive(head->info, info) == 0) {
    printf("[**REPEATED KEY**] [%s || %s]\n", head->info, info);
    return head;
  } // Node's value is greater
  else if (_scmpSensitive(head->info, info) < 0) {
    // We want to go to the left side of the tree (smaller values)
    // printf("[GOING LEFT] 1: %s || 2: %s\n", head->info, info);
    head->left = insertNode(head->left, info);
  } else {
    // printf("[GOING RIGHT] 1: %s || 2: %s\n", head->info, info);
    head->right = insertNode(head->right, info);
  }

  return head;
}

int main(int argc, char *argv[]) {
  int opt, caseFlag = 0, outputFlag = 0, inputFlag = 0;
  char infileName[BUFSIZE];
  char outfileName[BUFSIZE];

  char wordsList[BUFSIZE][BUFSIZE];

  while ((opt = getopt(argc, argv, "co:")) != -1) {
    // Check param.
    switch (opt) {
    case 'c':
      caseFlag = 1;
      break;
    case 'o':
      outputFlag = 1;
      strcpy(infileName, optarg);
    default:
      break;
    }
  }

  if (argc > optind)
    strcpy(outfileName, argv[argc - 1]);

  char word[BUFSIZE];

  node *head = createNode("sure");


  if (inputFlag == 0) {
    int i = 0;
    while (fgets(word, BUFSIZE, stdin) != NULL && word[0] != '\n') {
      strcpy(wordsList[i++], strtok(word, "\n \0"));
      insertNode(head, strLower(wordsList[i]));
    }
  }

  inorderTraversal(head);


  return 0;
}
