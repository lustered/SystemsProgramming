all: writer run1 run2 run3 run4 run5 updater urun1 urun2 urun3 urun4 \
	urun5 urun6 urun7 reader rrun1 rrun2 rrun3

writer: filehandling.c
	@printf "\n\n******************** First Program ********************\n"
	gcc -o writer filehandling.c

run1:
	@printf "\nUsing -l -f properly\n"
	-./writer -l -f foo1.txt is a beautiful day
run2:
	@printf "\n\nTesting -u and -f flags\n"
	-./writer -u -f foo2.txt is a sad day
run3:
	@printf "\n\nTesting only file flag\n"
	-./writer -f foo3.txt is a happy day
run4:
	@printf "\n\nTesting -lu flags\n"
	-./writer -lu -f foo4.txt this is a bad command
run5:
	@printf "\n\nTesting with non-registered flag\n"
	-./writer -x -f foo5.txt is this a good command

updater: updater.c
	@printf "\n\n******************** Second Program ********************\n"
	gcc -o updater updater.c

urun1:
	@printf "\nFirst proper sentence\n"
	-./updater -f bar.txt this is the first sentence
urun2:
	@printf "\nSecond proper sentence\n"
	-./updater -f bar.txt this is the 2nd sentence
urun3:
	@printf "\nThird proper sentence\n"
	-./updater -f bar.txt this is the 3rd sentence
urun4:
	@printf "\nFourth proper sentence\n"
	-./updater -f bar.txt this is the 4th sentence
urun5:
	@printf "\nFifth proper sentence\n"
	-./updater -f bar.txt this is the 5th sentence
urun6:
	@printf "\nLonger than 5 words sentence\n"
	-./updater -f bar.txt this is a very long sentence that should not work
urun7:
	@printf "\nNot using -f flag\n"
	-./updater why is this not providing a filename

reader: reader.c
	@printf "\n\n******************** Third Program ********************\n"
	gcc -o reader reader.c

rrun1:
	@printf "\nReading 5 lines\n"
	-./reader -f bar.txt 5
rrun2:
	@printf "\nReading 2 lines\n"
	-./reader -f bar.txt 2
rrun3:
	@printf "\nReading 7 lines\n"
	-./reader -f bar.txt 7

clean: 
	-rm *.o writer updater reader foo1.txt foo2.txt foo3.txt foo4.txt foo5.txt bar.txt
