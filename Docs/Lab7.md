Lab 7 Directions
Write a C program called threadcircuit to run on ocelot which will provide a multithreaded solution to the circuit-satisfiability problem which will compute for what combinations of input values will the circuit output the value 1. This is the sequential solution, which is also attached. You should create 8 threads and divide the 65,536 test cases among them. For example, if p=8, each thread would be responsible for roughly 65,536/8 number of iterations (if it's not divisible, some threads can end up with one more iteration than the others).

#include <stdio.h>
#include <sys/time.h>

// Return 1 if 'i'th bit of 'n' is 1; 0 otherwise
#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)

int check_circuit (int z) {
int v[16]; // Each element is a bit of z
int i;

for (i = 0; i < 16; i++) v[i] = EXTRACT_BIT(z,i);
if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
&& (!v[3] || !v[4]) && (v[4] || !v[5])
&& (v[5] || !v[6]) && (v[5] || v[6])
&& (v[6] || !v[15]) && (v[7] || !v[8])
&& (!v[7] || !v[13]) && (v[8] || v[9])
&& (v[8] || !v[9]) && (!v[9] || !v[10])
&& (v[9] || v[11]) && (v[10] || v[11])
&& (v[12] || v[13]) && (v[13] || !v[14])
&& (v[14] || v[15])) {
printf ("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",
v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],
v[10],v[11],v[12],v[13],v[14],v[15]);
return 1;
} else return 0;
}

int main (int argc, char \*argv[])
{
int count, i;

count = 0;
for (i = 0; i < 65536; i++)
count += check_circuit (i);

printf ("There are %d solutions\n", count);
return 0;
}

If a thread finds a combination that satisfies the circuit, it should print out the combination (like in the given sequential version), along with the thread id (a number between 0 and 7 (p-1)). In the end, the main thread should print out the total number of combinations that satisfy this circuit (like in the given sequential program). An example output of the program is shown below:

% threadcircuit 0) 0110111110011001 0) 1110111111011001 2) 1010111110011001

1. 1110111110011001
1. 1010111111011001
1. 0110111110111001
1. 1010111110111001
1. 0110111111011001
1. 1110111110111001
   There are 9 solutions
   The source file should have your name & Panther ID, a description and it should have the affirmation of originality included in a comment at the top.

Code should be nicely indented and commented.

Create a simple Makefile to compile your program into an executable called threadcircuit.

Take a screenshot of the screen showing the output on ocelot. Name it FirstNameLastName.png or .jpg.

Submit your source file, the screenshot and your Makefile in one zip file called FirstnameLastnameL7.zip to the assignment Submission Link in Canvas.

If the program does not compile and do something useful when it runs it will not earn any credit.
