all: salary t1 t2 t3 fail1 fail2 fail3 

salary: salary.c
	cc salary.c -o salary 

t1: 
	- @printf "\nTest 1: Pass\n"
	- ./salary -b 1000 -r 2 -v 60000
t2:
	- @printf "\nTest 2: Pass\n"
	- ./salary -v -r 5 50000
t3:
	- @printf "\nTest 3: Pass\n"
	- ./salary 40000

fail1:
	- @printf "\nTest 4: Fail\n"
	- ./salary -b 999 40000

fail2:
	- @printf "\nTest 5: Fail\n"
	- ./salary -b 5000 19999

fail3:
	- @printf "\nTest 6: Fail\n"
	- ./salary -b 5000 -r 11 60000

fail4:
	- @printf "\nTest 6: Fail\n"
	- ./salary -b 5000 -r 10 -v 60000
clean:
	- rm salary
