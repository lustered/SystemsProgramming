CC=mpicc
FLAGS=-O -Wall -lm

countprimes: countprimes.c
	$(CC) $(FLAGS) -o $@ $^

tests: countprimes
	@printf "\n"
	- mpirun -np 1 ./countprimes
	@printf "\n"
	- mpirun -np 2 ./countprimes
	@printf "\n"
	- mpirun -np 3 ./countprimes
	@printf "\n"
	- mpirun -np 4 ./countprimes
	@printf "\n"
	- mpirun -np 5 ./countprimes
	@printf "\n"
	- mpirun -np 6 ./countprimes
	@printf "\n"
	- mpirun -np 0 ./countprimes

clean:
	rm -f countprimes
