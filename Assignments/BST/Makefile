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

ptestfiles:
	@printf "apple\nAPPLE\nApple\nbanana\nBaNaNa\nBANANA\nbAnAnA\naPPLE\n\n" > ptestfile1
	@printf "apple\n\n" "APPLE\n\n" "banana\n\n" "Carrots\n\n" "Banana\n\n" > ptestfile2
	@printf "If\nyou\nlook\nat\nwhat\nyou\nhave\nin\nlife\nyou'll\n\
	always\nhave\nmore\nIf\nyou\nlook\nat\nwhat\nyou\ndon't\nhave\n\
	in\nlife\nyou'll\nnever\nhave\nenough\n" > ptestfile3

ptests: bstsort ptestfiles
	@printf "*********************************\n"
	./bstsort
	@printf "*********************************\n"
	./bstsort -c
	@printf "*********************************\n"
	./bstsort ptestfile1
	@printf "*********************************\n"
	./bstsort -c ptestfile1
	@printf "*********************************\n"
	./bstsort -o my_outfile1
	@printf "*********************************\n"
	./bstsort -c -o my_outfile2
	@printf "*********************************\n"
	./bstsort -o my_outfile3 ptestfile1
	@printf "*********************************\n"
	./bstsort -c -o my_outfile4 ptestfile1
	@printf "*********************************\n"
	./bstsort -o my_outfile5 ptestfile2
	@printf "*********************************\n"
	./bstsort -c -o my_outfile6 ptestfile2
	@printf "*********************************\n"
	./bstsort -o my_outfile7 ptestfile3
	@printf "*********************************\n"
	./bstsort -c -o my_outfile8 ptestfile3
	@printf "*********************************\n"

memoryleak: testfile bstsort
	- valgrind --track-origins=yes --leak-check=full ./bstsort -c -o \
		memoryTestOutput CarlosLuis_inputfile 

clean:
	- rm -f bstsort $(OUTPUT1) $(OUTPUT2) $(INPUTFILE) memoryTestOutput \
		my_outfile8 my_outfile7 my_outfile6 my_outfile5 my_outfile4 \
		my_outfile3 my_outfile2 my_outfile1 ptestfile3 ptestfile2 ptestfile1
