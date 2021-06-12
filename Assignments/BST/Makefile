CC = gcc
CFLAGS = -Wall
OUTPUT1 = test_output1
OUTPUT2 = test_output2
INPUTFILE = CarlosLuis_inputfile

bstsort: bstsort.c
	$(CC) $(CFLAGS) bstsort.c -o bstsort

testfile:
	@printf "apple\napple\nAPPLE\nAPPLE\nApple\nbanana\nBANANA\n" > $(INPUTFILE)

pass: bstsort testfile
	@printf "Creating test file: $(INPUTFILE)\n"
	@printf "\nTest1\n"
	- ./bstsort -o $(OUTPUT1) $(INPUTFILE)
	@printf "\nTest2\n"
	- ./bstsort -c -o $(OUTPUT2) $(INPUTFILE)
	@printf "\nRemoving test file: $(INPUTFILE)\n"
	@rm $(INPUTFILE)

fail: bstsort
	@printf "\nFail: Bad input file name\n"
	- ./bstsort -c wronginputfile

memoryleak: testfile bstsort
	- @valgrind --leak-check=full --track-origins=yes ./bstsort -c testout2 CarlosLuis_inputfile

clean:
	- rm -f bstsort $(OUTPUT1) $(OUTPUT2) $(INPUTFILE)
