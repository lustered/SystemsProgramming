Lab 2 Directions
Write a C program that runs on ocelot for a salary calculator using only the command line options. You must use getopt to parse the command line.

The calculator will only do bonuses and raises to a base salary as well as a veterans bump.

Usage: salary [-b num] [-r num] [-v] base

The variable base is the starting salary where the base should be validated to be an integer between 20000 and 60000 inclusive. It would represent a salary. Error message and usage shown if not valid.
For the -b option num should be a positive integer between 1000 and 10000 inclusive. It would represent a bonus on top of the salary. Error message and usage shown if not valid.
For the -r option num should be a positive integer between 1 and 10 inclusive. It would represent a percentage raise based on the salary. Error message and usage shown if not valid.
-b adds num to the base.
-r multiplies the base by the percentage given and adds it to the base.
-v adds a 5000 bump to the base.
Output should have exactly 2 decimal places no matter what the starting values are as we are talking about money.
If -v is included, it is executed first. If -r is included it would be executed next. The -b would be executed last.
There will be at most one of each option, if there are more than one you can use either of the options in the calculation.
The source file should have your name & Panther ID included in it as well as a program description and it should have the affirmation of originality from Lab 1.

Code should be nicely indented and commented. as in Lab 1.

Create a simple Makefile to compile your program into an executable called salary.

Test your program with the following command lines and take a screenshot after running the three lines. The command prompt should be viewable.

salary -b 1000 -r 2 -v 60000
salary -v -r 5 50000
salary 40000
You should submit the source code, the screenshot and your Makefile compressed into a zip file named FirstNameLastNameL2.zip. The screenshot should just be a file named with your FirstNameLastName.png or .jpg. The source file name should be named as desired as long as the Makefile works but ideally should be salary.c. The Makefile should be called Makefile with no extension. I should be able to type make at the command line to compile your program. Do not include any other files or folders in the zipfile.
