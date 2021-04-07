all: ptr run1 run2 run3 run4 run5 run6

ptr: cptr.c
	@printf "\n\n******************** First Program ********************\n"
	gcc -o ptr cptr.c

# Fail
run1:
	-./ptr 10

# Fail
run2:
	-./ptr 1 4

# Fail
run3:
	-./ptr 8

# Pass
run4:
	-./ptr 1

# Pass
run5:
	-./ptr 5

# None -> should default to 5
run6:
	-./ptr 

clean: 
	-rm *.o ptr 
