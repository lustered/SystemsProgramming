/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */
#include <stdio.h>

#define N_PARAMS 4 // Number of miles elements.

int main() {
  // Declare and initialize an array of miles.
  double miles[N_PARAMS] = {5.0, 1.75, 400.0, 2875.0};

  // Print header text with a divider.
  printf("|%-14s | %-11s|\n", "Miles", "Km");
  printf("------------------------------\n");

  // Iterate over all the miles to convert.
  for (int i = 0; i < N_PARAMS; ++i)
    // Formatted values: justified right, 5 decimal places.
    printf("|% 15.5f| % 11.5f|\n", miles[i], miles[i] * 1.60934);

  return 0;
}
