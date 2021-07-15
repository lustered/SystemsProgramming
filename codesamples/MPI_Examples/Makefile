all:	circuit complex-mpi-pi helloworld sendrecv seqcircuit simple-mpi-pi pi mpi_hello

circuit:	circuit.c
		mpicc -O -o circuit circuit.c

complex-mpi-pi: complex-mpi-pi.c
		mpicc -O -o complex-mpi-pi complex-mpi-pi.c

helloworld: helloworld.c
		mpicc -O -o helloworld helloworld.c

sendrecv: sendrecv.c
		mpicc -O -o sendrecv sendrecv.c

seqcircuit: seqcircuit.c
		mpicc -O -o seqcircuit seqcircuit.c

simple-mpi-pi: simple-mpi-pi.c
		mpicc -O -o simple-mpi-pi simple-mpi-pi.c

pi: pi.c
	mpicc -O -o pi pi.c	

mpi_hello: mpi_hello.c
	mpicc -O -o mpi_hello mpi_hello.c

clean:
		rm -f circuit complex-mpi-pi helloworld sendrecv seqcircuit pi mpi_hello simple-mpi-pi core *~
