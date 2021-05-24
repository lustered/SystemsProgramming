all: mywords t1

salary: mywords.c
	cc mywords.c -o mywords 
t1: 
	- @printf "\nTest 1: Pass\n"
	- ./mywords -c -s you testfile 
clean:
	- rm mywords
