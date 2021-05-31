Assignment #1 Instructions: Sorting with Binary Search Tree
Through this programming assignment, the students will learn to do the following:

Know how to process command line arguments.
Perform basic file I/O.
Use structs, pointers, and strings.
Use dynamic memory.
This assignment asks you to sort the words in an input file (or from standard input) and print the sorted words to an output file (or standard output). Your program, called bstsort (binary search tree sort), will take the following command line arguments:

% bstsort [-c] [-o output_file_name] [input_file_name]
If -c is present, the program needs to compare the strings case sensitive; otherwise, it's case insensitive. If the output_file_name is given with the -o option, the program will output the sorted words to the given output file; otherwise, the output shall be the standard output. Similarly, if the
input_file_name is given, the program will read from the input file; otherwise, the input will be from the standard input. You must use getopt() to parse the command line arguments to determine the cases.

In addition to parsing and processing the command line arguments, your program needs to do the following:

You need to construct a binary search tree as you read from input. A binary search tree is a binary tree. Each node can have at most two child nodes (one on the left and one on the right), both or either one can be empty. If a child node exists, it's the root of a binary search tree (we call subtree). Each node contains a key (in our case, it's a word which is a string). If the left subtree of a node exists, it contains only nodes with keys less than the node's key. If the right subtree of a node exists, it contains only nodes with keys greater than the node's key. You can look up binary search tree on the web or in your Data Structure textbook. Note that you do not need to balance the binary search tree (that is, you can ignore all those rotation operations) in this assignment.
Initially the tree is empty (that is, the root is null). The program reads from the input file (or stdin) one word at a time; As long as you continue reading words, if the word is not already in the tree, it should create a tree node that stores a pointer to the word and then insert the tree node to the binary search tree. If the word exists, then do not create a node. All duplicate words are ignored.
An empty line would indicate the end of input for stdin, an end of file would indicate the end of input for an input file.
You must develop two string comparison functions, one for case sensitive and the other for case insensitive. You must not use the strcmp() and strcasecmp() functions provided by the C library. You must implement your own version. You will be comparing the ASCII values. Note that using ASCII, all capital letters come before all lower case letters.
Once the program has read all the input (when EOF is returned or a blank line encountered), the program then performs an in-order traversal of the binary search tree to print out all the strings one word at a time to the output file or stdout. The output would be one word per line. If the selection was for case insensitive then you should use all lower case letters.
Before the program ends, it must reclaim the tree! You can do this by performing a post-order traversal, i.e., reclaiming the children nodes before reclaiming the node itself. Make sure you also reclaim the memory occupied by the string as well.
It is required that you use getopt for processing the command line and use malloc or calloc and free functions for dynamically allocating and deallocating nodes and the buffers for the strings. It is required that you implement your own string comparison functions instead of using the
corresponding libc functions.
Here's an example:

crahn@ocelot:~ 105% cat infile1summer
apple
apple
APPLE
APPLE
Apple
banana
BANANA
crahn@ocelot:~ 106% bstsort infile1summer
apple
banana
crahn@ocelot:~ 107% bstsort -c infilesummer
APPLE
Apple
BANANA
apple
banana
crahn@ocelot:~ 108% bstsort -o outfile1 infile1summer
crahn@ocelot:~ 109% cat outfile1
apple
banana
crahn@ocelot:~ 110%

Please submit your work through the inbox as one zip file. Follow the instructions below carefully (to avoid unnecessary loss of grade):
You should submit the source code and the Makefile in the zip file called FirstnameLastnameA1. One should be able to create the executable by simply 'make'. The Makefile should also contain a 'clean' target for cleaning up the directory (removing all object files at a minimum). Make sure
you don't include intermediate files: .o, executables, ~, etc., in your submission. (There'll be a penalty for including unnecessary intermediate files). Only two files should be included unless permission is given for more, those would be bstsort.c, and Makefile. If you feel a need to include a bstsort.h file, please send me a note with a copy of the file asking for permission.
