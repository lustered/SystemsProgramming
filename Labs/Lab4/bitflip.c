/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/* This program takes an integer and flips the bit at a specified position.
 * Usage: bitflip
 */

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t validate(char *num_src, uint32_t *num_dst) {
  // Get a pointer to the start of the string
  char *p = num_src;

  // Iterate through string
  while (p) {
    // If we reach the end of the string, assign the value
    if (*p == '\n' || *p == '\0') {
      *num_dst = (uint32_t)atoi(num_src);
    } else {
      // Check if the character is not a valid digit
      if (!isdigit(*p))
        // If it's not, return -1
        return -1;
    }

    // Go on to the next character
    p++;
  }

  return *num_dst;
}

int main() {

  // Declare and initialize variables
  uint32_t userNum = 0;
  uint32_t nth = 32; // Initialize as out-of-bounds

  // String to hold user input
  char *userInput = malloc(sizeof(char *) * 100);

  // Check for malloc failure
  if (userInput == NULL) {
    fprintf(stderr, "Malloc failed. Free up system resources.");
    exit(1);
  }

  // Get user input for the decimal
  do {
    printf("Please enter a number between 1-1000: ");
    scanf("%s", userInput);

    /* Validate the input. userNum will hold a valid digit and non-digit
     * user inputs are rejected
     */
    validate(userInput, &userNum);

  } while (userNum < 1 || userNum > 1000); // Check boundary

  // Print empty line
  putchar('\n');

  // Get user input for the position
  do {
    printf("Please enter the bit to flip between 0 and 31: ");
    scanf("%s", userInput);

    /* Validate the input. nth will hold a valid digit and non-digit
     * user inputs are rejected
     */
    validate(userInput, &nth);

  } while (nth < 0 || nth > 31); // Check boundary

  // Free up the string malloc'd
  free(userInput);

  /*
   * Breakdown:
   * (1 << nth position {2} ): 000001 (1) << 2 = 000100 (4)
   *
   * We apply bitwise xor:
   *
   *      001010 (10) userNum
   * xor  ||||||
   *      000100 (4) = 1 << 2 (nth position)
   *      ------
   *      001110 (2 + 4 + 8 = 14)
   */
  printf("New value: %u\n", userNum ^ (1 << nth));

  return 0;
}
