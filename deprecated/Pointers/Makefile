all: message ptr2 prun1 prun2 prun3 prun4 prun5 prun6 ptr run1 run2 run3 run4 run5 run6 

message:
	@printf "\nRunning the second program(cptr2) first since it does not quire input\n"

ptr2: cptr2.c
	@printf "\n******************** Second Program: cptr2 ********************\n"
	gcc -o ptr2 cptr2.c

prun1:
	-./ptr2 1 help people in need

prun2:
	-./ptr2 2 "what time is it" "how are you doing"

prun3:
	-./ptr2 3 "be kind" "be good" "show empathy"

prun4:
	-./ptr2 4

prun5:
	-./ptr2 2

prun6:
	-./ptr2 3 "be kind"

ptr: cptr.c
	@printf "\n\n******************** First Program: cptr ********************\n"
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
	-rm *.o ptr ptr2
