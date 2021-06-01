
  // printf("word check %s\n", wordsList[0]);
  // for(int i = 0; i < 3; i++ )
  //   printf("[Word %d] %s\n", i+1, wordsList[i]);

  // DEBUG ************************************
  // char words[12][BUFSIZE] = {"apple",  "Apple",  "APPLE", "BANANA",
  //                    "Banana", "banana", "banana"};
  // node *head = createNode("APPLE");
  // for (int i = 0; i < 7; i++)
  //   insertNode(head, strLower(words[i]));
  // inorderTraversal(head);
  //

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
