all: ptr2 prun1 prun2 prun3 prun4 prun5 prun6
# all: ptr run1 run2 run3 run4 run5 run6 ptr2 

ptr2: cptr2.c
	@printf "\n\n******************** Second Program ********************\n"
	gcc -o cptr2 cptr2.c

# ptr: cptr.c
# 	@printf "\n\n******************** First Program ********************\n"
# 	gcc -o ptr cptr.c

# Fail
# run1:
# 	-./ptr 10
# # Fail
# run2:
# 	-./ptr 1 4
# # Fail
# run3:
# 	-./ptr 8
# # Pass
# run4:
# 	-./ptr 1
# # Pass
# run5:
# 	-./ptr 5
# # None -> should default to 5
# run6:
# 	-./ptr 


prun1:
	-./cptr2 1 help people in need
prun2:
	-./cptr2 2 "what time is it"  "how are you doing"
prun3:
	-./cptr2 3 "be kind"  "be good"  "show empathy"
prun4:
	-./cptr2 4
prun5:
	-./cptr2 2
prun6:
	-./cptr2 3 "be kind"

clean: 
	-rm *.o ptr  cptr2
