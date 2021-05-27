Lab 4 Directions
Write a C program to run on ocelot which will flip a single bit in a number entered by the user using the binary representation of the number. The user should input the original integer value between 1 and 1000 inclusive using a scanf. Use an unsigned integer type. Output is to the screen. You must use only bitwise operators for this program. You can shift bits and or use the logical bitwise operators.

For this assignment give the user directions asking them to enter the integer. Then ask the user which bit to flip. That can be a number between 0 and 31 each referring to the values 20 to 231. Prompt the user for what should be entered each time. Be sure to validate all user input so the program cannot be crashed.

You do not need to use getopt for this program since there are no command line arguments

The source file should have your name & Panther ID, a description and it should have the affirmation of originality included in a comment at the top.

Code should be nicely indented and commented.

Create a simple Makefile to compile your program into an executable called bitflip.

If the user enters a 1 as the initial value and a 0 for the bit to flip the result would be 0.
If the user enters a 2 as the initial value and a 1 for the bit to flip the result would be 0.
If the user enters a 10 as the initial value and a 1 for the bit to flip the result would be 8.
Output should be easy to read.

Test the program with the following commands:

bitflip

then enter 16 as the initial value and a 2 for the bit to flip

bitflip

then enter 16 as the initial value and a 1 for the bit to flip

Take a screenshot of the screen showing the output on ocelot. Name it FirstNameLastName.png or .jpg.

Submit your source file, the screenshot and your Makefile in one zip file called FirstnameLastnameL4.zip to the assignment Submission Link in Canvas.
