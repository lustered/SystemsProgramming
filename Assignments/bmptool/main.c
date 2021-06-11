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

  *new = (PIXEL *)malloc(rows * cols * sizeof(PIXEL));

  for(int row = 0; row < rows; row++)
    for(int col = 0; col < cols; col++){
      PIXEL* o = original + row*cols + col;

      PIXEL* n = *new + (cols - col - 1) * rows + row;

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

  *new = (PIXEL *)malloc(rows * cols * sizeof(PIXEL));

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      // Grab a pointer to original's pixel i, j
      PIXEL *o = original + i * cols + j;

      // Grab a pixel
      PIXEL *n = (*new) + (rows - 1 - i) * cols + j - 1;
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
            int *newcols, float scale) {

  if ((rows <= 0) || (cols <= 0))
    return -1;

  *newrows = (rows * (int)scale);
  *newcols = (cols * (int)scale);

  *new = (PIXEL *)malloc(*newrows * *newcols * sizeof(PIXEL));

  for (int scan = 0; scan < *newrows; scan++) {
    PIXEL *o = original + (int)(scan / scale) * cols;
    PIXEL *n = *new + scan **newcols;

    for (int x = 0; x < cols; x++, o++)
      for (int i = 0; i < scale; i++)
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
  // enlarge(b, r, c, &nb, &nr, &nc, 3);
  rotate(b, r, c, &nb, &nr, &nc);
  writeFile("result.bmp", r, c, nb);

  // printf("Rows: %d | Columns: %d\n", r, c);
  // printf("New Rows: %d | New Columns: %d\n", nr, nc);

  free(b);
  free(nb);
  return 0;
}
