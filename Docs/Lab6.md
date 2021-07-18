Lab 6 Directions
Write an MPI program, countprimes which will count the number of prime numbers in the numbers
from 1 to n inclusive where n is a long integer. The value for n which should be set in the program using a constant should be 1,000,000.

. Each process will test its share of the cases.

. Each process should print out a count of the number of primes it found and its process number.

. The master process should end with printing a total for the count of the number of primes and the
total amount of time taken to find all the primes.

. Please follow the following instructions carefully before submitting your work:

. If the program does not compile using MPICC and do something useful when it runs it will not earn any credit.
The source file should have your name & Panther ID, a description and it should have the affirmation of originality included in a comment at the top.

. Code should be nicely indented and commented.

. Create a simple Makefile to compile your program into an executable called countprimes.

. Your Makefile can assume that the path to the MPI compiler is found in the path.

. The Makefile should also include a target 'clean' to clean up object files. Before submission, make sure you clean up the directories so that no miscellaneous files are kept around in the submission. (Grade would be deducted if useless files are found in the homework directories.)

Take a screenshot of the screen showing the output on ocelot. Name it FirstNameLastName.png or .jpg.

Submit your source file, the screenshot and your Makefile in one zip file called FirstnameLastnameL6.zip to the assignment Submission Link in Canvas.
If the program does not compile and do something useful when it runs it will not earn any credit.
