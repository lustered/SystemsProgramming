CC=gcc
CFLAGS=-Wall

mywords: mywords.c
	$(CC) $(CFLAGS) $< -o $@ 

testfile:
	@printf "Creating test file.\n"
	@echo "If you look at what you have in life, you'll always have more. \
	If you look at what you don't have in life, you'll never have enough." > CarlosLuis_testfile

tests: mywords testfile
	- @printf "\nTest 1: Pass\n"
	- ./mywords -c -s you CarlosLuis_testfile 
	- @printf "\nTest 2: Pass\n"
	- ./mywords -s you CarlosLuis_testfile 
	- @printf "\nTest 3: Pass\n"
	- ./mywords -c CarlosLuis_testfile 
	- @printf "\nTest 4: Fail - No filename\n"
	- ./mywords -s you
	- @printf "\nTest 5: Fail - No filename\n"
	- ./mywords -c 
	- @printf "\nTest 6: Fail - No substring\n"
	- ./mywords -s CarlosLuis_testfile 
	- @printf "\nTest 7: No flags passed\n"
	- ./mywords CarlosLuis_testfile 
	- @printf "\nRemoving test file\n"
	- @rm -f CarlosLuis_testfile

clean:
	- rm -f mywords CarlosLuis_testfile
