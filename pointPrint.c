#include <string.h>

int func(char* string, int* num, char* c)
{
   printf("Character: %c\n", *c);
   printf("Integer: %d\n", *num);
   printf("String: %s\n", string);

   (*num)--;
   return *num;
}
