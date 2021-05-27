Lab 3 Directions
Write a C program to run on ocelot to read a text file and print it to the display. It should optionally find the count of the number of words in the file, and/or find the number of occurrences of a substring. You must use getopt to parse the command line. There is no user input while this program is running.

Usage: mywords [-c] [-s substring] filename

The -c flag means to count the number of words in the file. A word would be a series of characters separated by spaces or punctuation. A word could include a hyphen or a single apostrophe.
The -s option will find the number of occurrences of the given substring.
You may have any number of the flags included or none of them.
The order they should be run would be: -c first and -s second.
Output should be well formatted and easy to read.
The source file should have your name & Panther ID, a description and it should have the affirmation of originality included in a comment at the top.

Code should be nicely indented and commented.

Create a simple Makefile to compile your program into an executable called mywords.

Test your program with the following:

Create an ASCII file named testfile with the text which is a quote by Oprah Winfrey.
"If you look at what you have in life, you'll always have more. If you look at what you don't have in life, you'll never have enough."

Use the command:
mywords -c -s you testfile

Take a screenshot of the screen showing the output on ocelot. Name it FirstNameLastName.png or .jpg.
Submit this assignment using the Canvas assignment Submission Link for Lab 3. You should submit the source code file, the screenshot and your Makefile compressed into a zip file named FirstNameLastNameL3.zip. Do not include the testfile as I will use my own file for testing.

The Makefile should be called Makefile with no extension. I should be able to type make at the command line to compile your program. Do not include any other files or folders in the zipfile.
