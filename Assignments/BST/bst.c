#include <stdio.h>
#include <stdlib.h>
#include <unistdio.h>

#define BUFSIZE 1000

typedef struct {
  int info;
  struct node *left;
  struct node *right;
  struct node *next;
} node;


node* create(int info){
  node* n = (node*) malloc(sizeof(node));
  n->info = info;
  n->right = NULL;
  n->left = NULL;
  n->next = NULL;

  return n;

}

typedef struct tree {
  node* words;

  node* head;
  node* tail;
} tree;

int main(){
  // DEBUG
  // *************************************************

  tree abc;
  abc.words = (node*) malloc(sizeof(node) * BUFSIZE);

  abc.words[0] = *create(5);
  printf("Node info:%d ", abc.words[0].info);

  // *************************************************




  return 0;
}
