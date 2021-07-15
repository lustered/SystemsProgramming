CC=mpicc
FLAGS=-O -lm

countprimes: countprimes.c
	$(CC) $(FLAGS) -o $@ $^

test: countprimes
	@printf "\n"
	mpirun -np 0 ./countprimes

clean:
	rm -f countprimes
