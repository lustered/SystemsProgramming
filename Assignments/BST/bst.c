/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program will create, insert and sort words in a binary search tree.
 * Usage: bstsort [-c] [-o output_file_name] [input_file_name]
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistdio.h>

#define BUFSIZE 100

typedef struct Node {
  char *info;
  struct Node *left;
  struct Node *right;
} Node;

// Create a node by initializing its key and next values
Node *createNode(char *info) {
  Node *ret = (Node *)malloc(sizeof(Node));
  ret->info = info;
  ret->right = NULL;
  ret->left = NULL;

  return ret;
}

// Convert entire string lowercase
char *strLower(char *string) {
  // Iterate over every char
  for (char *i = string; *i; i++)
    // Make each char lowercase
    *i = tolower(*i);

  return string;
}

// Compare strings as case sensitive
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

// Print each node in an in-order traversal fashion
void inorderTraversal(Node *node) {
  // If the node is NULL, we either reached the end of the list or the root was
  // null
  if (node == NULL)
    return;

  inorderTraversal((Node *)node->left);
  printf("[NODE]%s\n", node->info);
  inorderTraversal((Node *)node->right);
}

Node *insertNode(Node *head, char *info) {
  if (head == NULL)
    return createNode(info);

  if (_scmpSensitive(head->info, info) == 0) {
    printf("[**REPEATED KEY**] [%s || %s]\n", head->info, info);
    return head;
  } // Node's value is greater
  else if (_scmpSensitive(head->info, info) > 0) {
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
      strcpy(outfileName, optarg);
    default:
      break;
    }
  }

  // Grab input file
  if (argc > optind)
    strcpy(infileName, argv[argc - 1]);

  char word[BUFSIZE];

  Node *head = createNode("Something");

  if (inputFlag == 0) {
    int i = 0;
    while (fgets(word, BUFSIZE, stdin) != NULL && word[0] != '\n') {
      word[strcspn(word, "\n\0")] = 0;
      strcpy(wordsList[i], word);

      // Define if the word should be case sensitive or not by the optarg flag.
      char *isCaseSensitive = (caseFlag) ? wordsList[i++] 
                                         : strLower(wordsList[i++]);

      insertNode(head, isCaseSensitive);
    }
  }

  inorderTraversal(head);

  return 0;
}
