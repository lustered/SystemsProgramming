all: forkchildren2 forkchildren5

forkchildren2: forkchildren2.c 
	@printf "\n *********************************************** \n"
	gcc -o fork2 forkchildren2.c
	-./fork2

forkchildren5: forkchildren5.c 
	@printf "\n *********************************************** \n"
	gcc -o fork5 forkchildren5.c
	-./fork5

clean:
	-rm fork5 fork2
