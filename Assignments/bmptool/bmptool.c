#include "bmplib.h"
#include <stdio.h>
#include <stdlib.h>

// TODO TODO TODO: ADD COMMENTS - REFORMAT

/*
 * This method rotates a 24-bit, uncompressed .bmp file 90 degrees clockwise
 * that has been read in using readFile().
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
int rotate(PIXEL *original, int rows, int cols, PIXEL **new, int *newrows,
           int *newcols) {

  if ((rows <= 0) || (cols <= 0))
    return -1;

  *new = malloc(rows * cols * sizeof(PIXEL));

  *newcols = rows;
  *newrows = cols;

  /* Using a single loop, keep in mind:
   * row = i / cols;
   * col = i % cols;
   */
  for (int i = 0; i < rows * cols; i++) {

    // Grab a pointer to original's pixel i, j
    PIXEL *o = original + (i / cols) * cols + (i % cols);

    // Grab the pixel at the corresponding position in the new photo
    PIXEL *n = *new + (*newcols - (i % *newcols) - 1) * *newrows + (i / *newcols);

    // Copy the original's pixel to the new photo
    *n = *o;
  }

  return 0;
}

/*
 * This method Vertically flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */

/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
int flip(PIXEL *original, PIXEL **new, int rows, int cols) {
  int row, col;

  if ((rows <= 0) || (cols <= 0))
    return -1;

  *new = (PIXEL *)malloc(rows * cols * sizeof(PIXEL));

  for (row = 0; row < rows; row++)
    for (col = 0; col < cols; col++) {
      PIXEL *o = original + row * cols + col;
      PIXEL *n = (*new) + row * cols + (cols - 1 - col);
      *n = *o;
    }

  return 0;
}

int verticalflip(PIXEL *original, PIXEL **new, int rows, int cols) {
  if ((rows <= 0) || (cols <= 0))
    return -1;

  *new = malloc(rows * cols * sizeof(PIXEL));

  /* Using a single loop, keep in mind:
   * row = i / cols;
   * col = i % cols;
   */
  for (int i = 0; i < rows * cols; i++) {
    // Grab a pointer to original's pixel i, j
    PIXEL *o = original + (i / cols) * cols + (i % cols);

    // Grab the pixel at the corresponding position in the new photo
    PIXEL *n = (*new) + (rows - 1 - (i / cols)) * cols + (i % cols) - 1;

    // Copy the original's pixel to the new photo
    *n = *o;
  }

  return 0;
}

/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */
int enlarge(PIXEL *original, int rows, int cols, PIXEL **new, int *newrows,
            int *newcols) {

  if ((rows <= 0) || (cols <= 0))
    return -1;

  // Fixed scale factor
  double scale = 2;

  // Declare new rows
  *newrows = (rows * (int)scale);
  *newcols = (cols * (int)scale);

  *new = malloc(*newrows * *newcols * sizeof(PIXEL));

  for (int i = 0; i < *newrows; i++) {
    PIXEL *o = original + (int)(i / scale) * cols;
    PIXEL *n = *new + i * *newcols;

    for (int x = 0; x < cols; x++, o++)
      for (int y = 0; y < scale; y++)
        *n++ = *o;
  }

  return 0;
}

int main() {
  int r, c;
  int nr, nc;
  PIXEL *b, *nb;

  readFile("example.bmp", &r, &c, &b);
  // flip(b, &nb, r, c);
  // verticalflip(b, &nb, r, c);
  // writeFile("result.bmp", r, c, nb);

  // rotate(b, r, c, &nb, &nr, &nc);
  enlarge(b, r, c, &nb, &nr, &nc);
  writeFile("result.bmp", nr, nc, nb);

  // printf("Rows: %d | Columns: %d\n", r, c);
  // printf("New Rows: %d | New Columns: %d\n", nr, nc);

  free(b);
  free(nb);
  return 0;
}
