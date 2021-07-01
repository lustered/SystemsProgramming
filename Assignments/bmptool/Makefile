bmptool:	bmplib.o bmptool.o
	$(CC) bmplib.o bmptool.o -o $@

bmplib.o:	bmplib.c bmplib.h
	$(CC) -Wall -c $< -o $@

bmptool.o:	bmptool.c bmplib.h 
	$(CC) -Wall -c $< -o $@

tests: bmptool
	- ./bmptool -s -r -o ret example.bmp
	@feh ret

clean:
	rm -f bmptool *.o core *~ result.bmp
