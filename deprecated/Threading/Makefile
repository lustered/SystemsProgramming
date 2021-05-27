all: t1 t2 run1 run2

t1: thread1.c
	gcc -pthread -o t1 thread1.c

t2: thread1.c
	gcc -pthread -o t2 thread2.c

run1:
	./t1

run2:
	./t2

clean:
	-rm t1 t2 *.o
