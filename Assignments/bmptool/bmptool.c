/* Name: Carlos Luis
 * Panther ID: 6271656
 *
 * I affirm that I wrote this program myself without any help from any other
 * people or sources from the internet.
 */

/*
 * This program will transform 24-bit uncompressed .bmp files. The possible
 * transformation options are:
 *
 *   - [-s] Enlarge (resize) image by a factor of 2.
 *   - [-r] Rotate 90 degrees clockwise.
 *   - [-v] Flip the image vertically.
 *   - [-f] Flip the image horizontally.
 *
 * Usage: bmptool [-f | -r | -s | -v ] [-o output_file] [input_file]
 *
 * It is also possible to chain commands using pipes such as:
 *
 * bmptool -s -r example.bmp | bmptool -v -o ret_image
 *
 */

#include "bmplib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

  // Declare new rows and cols
  *newrows = rows * 2;
  *newcols = cols * 2;

  // Allocate memory for the new bitmap
  *new = (PIXEL *)malloc((*newrows) * (*newcols) * sizeof(PIXEL));

  for (int i = 0; i < *newrows; i++) {
    // Iterate through the rows of the original image
    PIXEL *o = original + (i / 2) * cols;
    // Grab a pointer to its respective column in the new image
    PIXEL *n = *new + (i * *newcols);

    /* Write each column(scaled) to the new bitmap.
     *
     * We can see the process if we half cols in the following for loop,
     * and only half of the image's columns will be seen.
     */
    for (int y = 0; y < cols; y++, o++)
      *n++ = *o, *n++ = *o;
  }

  return 0;
}

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

  // Declare new rows and cols
  *newcols = rows;
  *newrows = cols;

  // Allocate memory for the new bitmap
  *new = (PIXEL *)malloc(*newrows * *newcols * sizeof(PIXEL));

  /* Using a single loop, keep in mind:
   * row = i / cols;
   * col = i % cols;
   */
  for (int i = 0; i < rows * cols; i++) {

    // Grab a pointer to original's pixel i, j
    PIXEL *o = original + (i / cols) * cols + (i % cols);

    // Grab the pixel at the corresponding position in the new image
    PIXEL *n =
        *new + (*newrows - (i % *newrows) - 1) * *newcols + (i / *newrows);

    // Copy the original's pixel to the new image
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
int verticalflip(PIXEL *original, PIXEL **new, int rows, int cols) {
  if ((rows <= 0) || (cols <= 0))
    return -1;

  // Allocate memory for the new bitmap
  *new = (PIXEL *)malloc(rows * cols * sizeof(PIXEL));

  /* Using a single loop, keep in mind:
   * row = i / cols;
   * col = i % cols;
   */
  for (int i = 0; i < rows * cols; i++) {
    // Grab a pointer to original's pixel i, j
    PIXEL *o = original + (i / cols) * cols + (i % cols);

    // Grab the pixel at the corresponding position in the new image
    PIXEL *n = (*new) + (rows - 1 - (i / cols)) * cols + (i % cols);

    // Copy the original's pixel to the new image
    *n = *o;
  }

  return 0;
}

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

int main(int argc, char *argv[]) {
  int opt, fflag = 0, rflag = 0, sflag = 0, vflag = 0;

  // Declare in/out files. Initializing them to NULL so if they're not assigned,
  // readFile will read from stdin, and writeFile will output to stdout
  char *outputFile = NULL;
  char *inputFile = NULL;

  // Keep track of how many bitmaps will be created.
  int bitmapcount = 1;

  const char usage[] = {
      "bmptool [-f | -r | -s | -v ] [-o output_file] [input_file]\n"};

  // Check for parameter flags
  while ((opt = getopt(argc, argv, "frsvo:")) != -1) {
    // Check param.
    switch (opt) {
    case 'f': // Flip horizontally
      // Increase flag count if it's the first time it's being passed
      if (!fflag)
        bitmapcount++;
      fflag = 1;
      break;
    case 'r': // Rotate 90 degrees clockwise
      // Increase flag count if it's the first time it's being passed
      if (!rflag)
        bitmapcount++;
      rflag = 1;
      break;
    case 's': // Scale by factor of 2
      // Increase flag count if it's the first time it's being passed
      if (!sflag)
        bitmapcount++;
      sflag = 1;
      break;
    case 'v': // Vertical flip
      // Increase flag count if it's the first time it's being passed
      if (!vflag)
        bitmapcount++;
      vflag = 1;
      break;
    case 'o': // Specified output file flag
      outputFile = optarg;
      break;
    case '?':
    default:
      fprintf(stderr, usage);
      exit(1);
    }
  }

  // Grab input file and check it exists. If it does, stdin will be the file
  if (argc > optind) {
    if (access(argv[argc - 1], F_OK) == 0) // Check the file exists
      inputFile = argv[argc - 1];
    else { // Input file does not exist
      fprintf(stderr, "Input file does not exist.\n%s", usage);
      exit(1);
    }
  }

  // Define row, col
  int r = 0, c = 0;
  // Define newrow, newcol
  int nr = 0, nc = 0;

  PIXEL *bitmaps[5]; // Define an array of bitmaps

  int idx = 0; // keep track of index

  // Read from either stdin or input file passed
  readFile(inputFile, &r, &c, &bitmaps[0]);

  // Enlarge bmp image by factor of 2
  if (sflag) {
    enlarge(bitmaps[idx], r, c, &bitmaps[idx + 1], &nr, &nc);

    // Update row/col
    r = nr;
    c = nc;

    idx++;
  }

  // Rotate image 90 degrees clockwise
  if (rflag) {
    rotate(bitmaps[idx], r, c, &bitmaps[idx + 1], &nr, &nc);

    // Update row/col
    r = nr;
    c = nc;

    idx++;
  }

  // Flip image vertically
  if (vflag) {
    verticalflip(bitmaps[idx], &bitmaps[idx + 1], r, c);

    idx++;
  }

  // Flip image horizontally
  if (fflag) {
    flip(bitmaps[idx], &bitmaps[idx + 1], r, c);

    idx++;
  }

  // Write to either stdout or defined output file
  writeFile(outputFile, r, c, bitmaps[idx]);

  // Free up allocated memory
  for (int i = 0; i < bitmapcount; i++)
    free(bitmaps[i]);

  return 0;
}
