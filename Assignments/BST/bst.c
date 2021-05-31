#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistdio.h>

#define BUFSIZE 1000

typedef struct {
  char *info;
  struct node *left;
  struct node *right;
} node;

typedef struct tree {
  node *words;
  // node *head;
  int pos;
} tree;

node *createNode(char *info) {
  node *n = (node *)malloc(sizeof(node));
  n->info = info;
  n->right = NULL;
  n->left = NULL;

  return n;
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

void inorderTraversal(tree *bst, node *n, char *info) {
  if (n == NULL)
    return;
  inorderTraversal(bst, (node *)n->left, info);
  printf("%s", n->info);
  inorderTraversal(bst, (node *)n->right, info);
}

// TODO TODO
// void orderNodes(node *n, char *info){

//   // Equals case: Don't add anything
//   if (_scmpInsensitive(n->info, info) == 0)
//     return;
//   else if (_scmpInsensitive(n->info, info) > 0) { // Node's value is greater
//     char* tmp = n->info;
//     n->info = info;


//   } else // Node value is smaller
//     ;
// }

// void insertNodeList(tree *bst, char *info) {
void insertNodeList(node *n, char *info) {
  if (n->info == NULL) {
    n->info = info;
    return;
  }

  insertNodeList((node*) n->left, info);
  insertNodeList((node*) n->right, info);
}

void insertNodeArray(char *info, tree *bst) {
  bst->words[bst->pos] = *createNode(info);
  bst->pos++;
}

int main() {
  // DEBUG
  // *************************************************
  tree abc;
  abc.words = (node *)malloc(sizeof(node) * BUFSIZE);

  // Linked list implementation
  for(int i = 0; i < 50; i++)
    insertNodeList(node *n, char *info)

  // !!!!!!!!!! Array implementation !!!!!!!!!
  // abc.pos = 0;
  // for (int i = 0; i < 50; i++)
  //   insertNodeArray("askjdhaskjdh", &abc);

  // for (int i = 0; i < abc.pos; i++)
  //   printf("Node[%d] || info:%s\n", i,abc.words[i].info);
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  // Free up memory in the heap *********
  // for (int i = 0; i < BUFSIZE; i++) {
  //   free(abc.words[i].left);
  //   free(abc.words[i].right);
  // }
  // free(abc.words);

  // String compare testing
  // char* s1 = "qwer";
  // char* s2 = "abc";
  // printf("Testing: %d", _scmpInsensitive(s1, s2));

  // *************************************************

  return 0;
}
