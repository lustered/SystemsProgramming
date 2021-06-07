CC = gcc
CFLAGS = -Wall

bstsort: bstsort.c
	$(CC) $(CFLAGS) bstsort.c -o bstsort

testfile:
	@printf "apple\napple\nAPPLE\nAPPLE\nApple\nbanana\nBANANA\n" > CarlosLuis_inputfile

pass: bstsort testfile
	@printf "Creating test file: CarlosLuis_inputfile\n"
	@printf "\nTest1\n"
	- ./bstsort -o test1.txt CarlosLuis_inputfile
	@printf "\nTest2\n"
	- ./bstsort -c -o test2.txt CarlosLuis_inputfile
	@printf "\nRemoving test file: CarlosLuis_inputfile\n"
	@rm CarlosLuis_inputfile

fail: bstsort
	@printf "\nFail: Bad input file name\n"
	- ./bstsort -c wronginputfile

clean:
	- rm -f bstsort test1.txt test2.txt 
