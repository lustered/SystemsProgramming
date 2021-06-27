CC=gcc
CFLAGS=-Wall
OUTPUT1=test_output1
OUTPUT2=test_output2
INPUTFILE=CarlosLuis_inputfile

bstsort: bstsort.c
	$(CC) $(CFLAGS) $< -o $@

testfile:
	@printf "Creating test file.\n"
	@printf "apple\napple\nAPPLE\nAPPLE\nApple\nbanana\nBANANA\n" > $(INPUTFILE)

tests: bstsort testfile
	@printf "Creating test file: $(INPUTFILE)\n"
	@printf "\nTest 1\n"
	- ./bstsort -o $(OUTPUT1) $(INPUTFILE)
	@printf "\nTest 2\n"
	- ./bstsort -c -o $(OUTPUT2) $(INPUTFILE)
	@printf "\nRemoving test file: $(INPUTFILE)\n"
	@rm $(INPUTFILE)
	@printf "\nTest 3: fail - bad input file name\n"
	- ./bstsort -c wronginputfile

memoryleak: testfile bstsort
	- valgrind --track-origins=yes --leak-check=full ./bstsort -c -o \
		memoryTestOutput CarlosLuis_inputfile 

clean:
	- rm -f bstsort $(OUTPUT1) $(OUTPUT2) $(INPUTFILE) memoryTestOutput
