# all: salary pass fail fail2
all: salary t1 t2 t3

salary: salary.c
	cc salary.c -o salary 

# fail: 
# 	@printf "\nFailing test\n"
# 	- ./salary -b 25000 10000

# fail2: 
# 	@printf "\nFailing test with no base\n"
# 	- ./salary -b 10000 

# pass: 
# 	@printf "\nPassing test\n"
# 	- ./salary -b 10000 25000

t1:
	# - ./salary -b 1000 -r 2 -v 60000
	./salary -r 2 -v 60000
t2:
	- ./salary -v -r 5 50000
t3:
	- ./salary 40000
