all: mywords test1 test2 test3 test4 test5

salary: mywords.c
	cc mywords.c -o mywords 
test1: 
	- @printf "\nTest 1: Pass\n"
	- ./mywords -c -s you testfile 

test2: 
	- @printf "\nTest 2: Pass\n"
	- ./mywords -s you testfile 

test3: 
	- @printf "\nTest 3: Pass\n"
	- ./mywords -c testfile 

test4: 
	- @printf "\nTest 4: Fail - No filename\n"
	- ./mywords -s testsubstring

test5: 
	- @printf "\nTest 5: Fail - No filename\n"
	- ./mywords -c 
clean:
	- rm mywords
