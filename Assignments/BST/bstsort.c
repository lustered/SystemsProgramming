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

// Size for strings
#define BUFSIZE 1000

// Define a node structure that represents a node in a Binary Search Tree
typedef struct Node {
  char *info;         // Key
  struct Node *left;  // Smaller values
  struct Node *right; // Great values
} Node;

// Create a node and initialize its key and next values
Node *createNode() {
  Node *ret = (Node *)malloc(sizeof(Node)); // Allocate memory
  ret->info = NULL;
  ret->right = NULL;
  ret->left = NULL;

  return ret;
}

// Convert an entire string lowercase
char *strLower(char *string) {
  // Iterate over every char
  for (char *i = string; *i; i++)
    *i = tolower(*i); // Make each char lowercase

  return string;
}

// Compare strings as case sensitive
int _scmpSensitive(char *string1, char *string2) {

  // Temporary characters. They will be used to compare each char in the string
  unsigned char ch1, ch2;

  // Iterate until there's a different character
  while (ch1 == ch2) {
    // Grab each character
    ch1 = (unsigned char)*string1++;
    ch2 = (unsigned char)*string2++;

    // Check if either string reached the end
    if (ch1 == '\0' || ch2 == '\0')
      // if the end is reached, return the value
      return ch1 - ch2;
  }

  // If the characters weren't equal, return the value at that position
  return ch1 - ch2;
}

// Print each node in-order traversal fashion
void inorderTraversal(Node *head) {
  // If the node is NULL, we either reached the end of the list or the root
  // wasn't initialized
  if (head == NULL)
    return;

  inorderTraversal(head->left); // Traverse the left(smaller) nodes first

  // Print the node as it unwinds from  the recursion
  printf("%s\n", head->info);

  inorderTraversal(head->right); // Traverse the right(greawter) nodes
}

void freeTree(Node *node) {
  if (node == NULL)
    return;

  // Traverse the entire list
  freeTree(node->left);
  freeTree(node->right);

  // Deallocate the memory allocated for the info strings and node as it unwinds
  free(node->info);
  free(node);
}

Node *insertNode(Node *head, char *info) {
  // Node mem wasn't allocated yet
  if (head == NULL)
    head = createNode();

  // Mem was allocated but a key wasn't inserted
  if (head->info == NULL) {
    head->info = info;
    return head;
  }

  // Reject repeated keys
  if (_scmpSensitive(head->info, info) == 0) {
    // printf("[**REPEATED KEY**] [%s || %s]\n", head->info, info);
    return head;
  } else if (_scmpSensitive(head->info, info) > 0) {
    // Traverse left side of the tree (greater values)
    // printf("[GOING LEFT] 1: %s || 2: %s\n", head->info, info);
    head->left = insertNode(head->left, info);
  } else {
    // Traverse right side of the tree (smaller values)
    // printf("[GOING RIGHT] 1: %s || 2: %s\n", head->info, info);
    head->right = insertNode(head->right, info);
  }

  return head;
}

int main(int argc, char *argv[]) {
  // Declare and initialize optarg flags
  int opt, caseFlag = 0, outputFlag = 0;

  // String to grab output file
  char outfileName[BUFSIZE];

  char usage[] = {"Usage: bstsort [-c] [-o output_file] [input_file]\n"};

  // Check for parameter flags
  while ((opt = getopt(argc, argv, "co:")) != -1) {
    // Check param.
    switch (opt) {
    case 'c': // Case sensitive flag
      caseFlag = 1;
      break;
    case 'o': // Specified output file flag
      outputFlag = 1;
      strcpy(outfileName, optarg);
      break;
    default: // Wrong flag passed
      fprintf(stderr, "%s\n", usage);
      exit(1);
    }
  }

  // Grab input file and check it exists. If it does, stdin will be the file
  if (argc > optind) {
    if (access(argv[argc - 1], F_OK) == 0) // Check the file exists
      freopen(argv[argc - 1], "r", stdin); // The file will be in stdin buffer
    else {
      fprintf(stderr, "Input file does not exist\n"); // Display error message
      exit(1);
    }
  }

  // Create a root node and initialize it
  Node *head = createNode();

  // String to read each line from stdin
  char buffer[BUFSIZE];

  // Read each line until the line is an empty line
  while (fgets(buffer, BUFSIZE, stdin) != NULL && buffer[0] != '\n') {

    // Strip terminator and newlines characters
    buffer[strcspn(buffer, "\n\0")] = 0;

    // Put the word in the buffer in a string
    char *word = malloc(BUFSIZE);
    strcpy(word, buffer);

    // Check the word should be case sensitive or not by the optarg flag
    word = (caseFlag) ? word : strLower(word);

    insertNode(head, word); // Insert the word in the bst
  }

  // Check if the output flag was specified
  if (outputFlag)
    freopen(outfileName, "w", stdout); // Send stdout to output file

  inorderTraversal(head);           // Print nodes in in-order traversal
  freopen("/dev/tty", "a", stdout); // Return to the terminal's stdout

  // printf("Before deallocating memory: %s\n", head->info);
  freeTree(head);
  // printf("After deallocating memory: %s\n", head->info);

  return 0;
}
