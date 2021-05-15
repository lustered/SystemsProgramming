#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int EXIT_MSG() {
  printf("\nUsage: salary [-b num] [-r num] [-v] base\n");
  printf("Option base has to be in the range: 20000 <= base <= 60000\n");
  printf("Option [-b] has to be in the range: 1000 <= b <= 10000\n");
  printf("Option [-r] has to be in the range: 1 <= b <= 10\n");
  return 1;
}
int main(int argc, char *argv[]) {
  int opt;

  int base = 0;
  int bopt = 0;
  int ropt = 0;
  int vopt = 0;

  if (atoi(argv[argc - 1]) < 20000 || atoi(argv[argc - 1]) > 60000)
    exit(EXIT_MSG());
  else
    base = atoi(argv[argc - 1]);

  while ((opt = getopt(argc, argv, "b:r:v")) != -1) {
    switch (opt) {
    case 'b':
      if (atoi(optarg) < 1000 || atoi(optarg) > 10000)
        exit(EXIT_MSG());
      bopt = atoi(optarg);
      break;
    case 'r':
      if (atoi(optarg) < 1 || atoi(optarg) > 10)
        exit(EXIT_MSG());
      ropt = atoi(optarg);

      break;
    case 'v':
      vopt = 1;
      break;
    default:
      printf("\nUsage: salary [-b num] [-r num] [-v] base\n");
      exit(1);
      break;
    }

    if (vopt) {
      base += 5000;
      printf("Veteran: +5000\n");
    }

    if (ropt != 0){
      printf("Percentage: +%d%%\n", ropt);
      base += base * ropt;
    }

    if (bopt){
      printf("Bump: %d\n", bopt);
      base += bopt;
    }

    printf("Salary: %.2d\n", base);

    return 0;
  }
}
