bmptool:	bmplib.o bmptool.o
	$(CC) bmplib.o bmptool.o -o $@

bmplib.o:	bmplib.c bmplib.h
	$(CC) -Wall -c $< -o $@

bmptool.o:	bmptool.c bmplib.h 
	$(CC) -Wall -c $< -o $@

tests: bmptool
	./bmptool -v -o 1.bmp example.bmp
	./bmptool -r -o 2.bmp example.bmp
	./bmptool -f -o 3.bmp example.bmp
	./bmptool -s -o 4.bmp example.bmp
	./bmptool -r -f -o 5.bmp example.bmp
	./bmptool -r -s -r -s -o 6.bmp example.bmp
	./bmptool -f -r -s -o 7.bmp example.bmp
	./bmptool -s example.bmp | ./bmptool -r | ./bmptool -f -o 8.bmp
	./bmptool -f example.bmp | ./bmptool -f -o 9.bmp

clean:
	rm -f bmptool *.o core *~ result.bmp 1.bmp 2.bmp 3.bmp 4.bmp 5.bmp 6.bmp \
	7.bmp 8.bmp 9.bmp
