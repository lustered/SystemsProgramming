#include <stdio.h>
#include <stdlib.h>
#include "pointPrint.c"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("ERROR (Incorrect Argument count)\n");
        return -1;
    }
    int num = argv[1][0] - 48;
    char c = argv[2][0];

    if (num > 3 || num < 1 || argv[1][1]) // Number more than 1 digit or not in limit(1-3)
    {
        printf("ERROR (Incorrect Number Entered)\n");
        return -1;
    }
    else if (argc != num + 2)
    {
        printf("ERROR (Incorrect Argument count)\n");
        return -1;
    }

    char** strings = malloc(num * sizeof(char*));
    for (int i = 0; i < num; ++i)
        strings[i] = argv[i + 2];

    while (num)
    {

        c = strings[argv[1][0] - 48 - num][0];
        func(strings[argv[1][0] - 48 - num], &num, &c);
    }

    return 0;
}
