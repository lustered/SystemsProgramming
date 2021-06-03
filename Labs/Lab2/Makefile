CC = gcc
CFLAGS = -Wall

test: tests
fail: failcases

salary: salary.c
	$(CC) $(CFLAGS) salary.c -o salary 

tests: salary
	@printf "\n"
	./salary -b 1000 -r 2 -v 60000
	@printf "\n"
	./salary -v -r 5 50000
	@printf "\n"
	./salary 40000

# Make fail
failcases: salary
	@printf "\nFail: Test 4 bad base\n"
	- ./salary -b 1000 -r 2 -v 3000
	@printf "\nFail: Test 5 bad bonus\n"
	- ./salary -b 999 -r 2 -v 60000
	@printf "\nFail: Test 6 bad percentage\n"
	- ./salary -b 10000 -r 11 -v 60000

clean:
	- rm salary
