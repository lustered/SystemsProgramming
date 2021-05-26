/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program takes an integer and flips the bit at a specified position.
 * Usage: bitflip
 */

#include <stdio.h>

int main() {

  unsigned int userNum = 0;
  int flip = 0;

  do {
    printf("Please enter a number between 1-100: ");
    scanf("%u", &userNum);

  } while (userNum < 1 || userNum > 1000);

  do {
    printf("Please enter the bit to flip between 0 and 31: ");
    scanf("%d", &flip);
  } while (flip < 0 || flip > 31);

  printf("New value: %u\n", userNum ^ flip);

  return 0;
}