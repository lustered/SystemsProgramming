Lab 5 Directions
Carefully study the examples provided: fork.c, myls.c, myshell.c, etc. You need to know how they work in order for you to finish this assignment; the examples will also get you prepared for assignment 3.

Write a C program called counter to run on ocelot which will chain some Unix utility programs. Your program should produce the same output as the following shell script after the code is completed. You must name your source file counter.c for this to work.

sort counter.c | grep main | wc
You will fork off a total of three children. One to run sort, one to run grep and one to run wc.

. sort is a Unix utility program that sorts the text file by lines. By default, it reads from the standard input and writes the sorted text to the standard output.

. The standard output of sort is "piped" as the standard input of the command grep following '|'. grep is another utility program which is a file pattern searcher. It takes one command-line argument (the word 'main') and searches for matches line by line from the standard input. When a match is found (a line that contains the word 'main'), the program prints the line to the standard output.

. The standard output of grep is again 'piped' as the standard input of the command wc following (the second) '|' . wc is a word/line/character counter It takes the standard input and counts the lines, words, and characters, and prints out the results to the standard output.

. Note that you're not asked to implement these utility programs. You are asked to fork processes and use exec (or its variants) to run the utility programs. These utility programs can be found in the system directories (if interested, you can use the command 'which program_name' in a shell to find out exactly where the utility programs are located). You are also asked to use pipe and dup2 to facilitate communication between the processes (i.e., rewiring the standard input and output for the processes before you exec them).

You do not need to use getopt for this program since there are no command line arguments. You will run the program by typing "counter".

The source file should have your name & Panther ID, a description and it should have the affirmation of originality included in a comment at the top.

Code should be nicely indented and commented.

Create a simple Makefile to compile your program into an executable called counter. The Makefile should
also include a target 'clean' to clean up object files. Before submission, make sure you clean up the directories so that no miscellaneous files are kept around in the submission. (Grade would be deducted if useless files are found in the homework directories.)

Take a screenshot of the screen showing the output on ocelot. Name it FirstNameLastName.png or .jpg.

Submit your source file, the screenshot and your Makefile in one zip file called FirstnameLastnameL5.zip to the assignment Submission Link in Canvas.

If the program does not compile and do something useful when it runs it will not earn any credit.
