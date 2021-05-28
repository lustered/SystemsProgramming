/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program takes an integer and flips the bit at a specified position.
 * Usage: bitflip
 */

#include <stdint.h>
#include <stdio.h>

int main() {

  uint32_t userNum = 0;
  int nth = 0;

  do {
    printf("Please enter a number between 1-1000: ");
    scanf("%u", &userNum);

  } while (userNum < 1 || userNum > 1000);

  do {
    printf("Please enter the bit to flip between 0 and 31: ");
    scanf("%d", &nth);
  } while (nth < 0 || nth > 31);

  // Breakdown:
  // (1 << nth position {2} ) 32 bit: 000001 << 2 = 000100 (4)
  //    001010 (10) userNum
  // xor
  //    000100 (4) 1 << nth
  //    ------
  //    001110 (14)
  printf("New value: %u\n", userNum ^ (1 << nth));

  return 0;
}
