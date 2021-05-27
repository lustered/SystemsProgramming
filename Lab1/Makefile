CC = gcc
CFLAGS = -Wall

test: run

convertmiles: convertmiles.c
	$(CC) $(CFLAGS) -o convertmiles convertmiles.c 

run: convertmiles
	./convertmiles

clean:
	 - rm convertmiles
