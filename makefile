CC=gcc
LIB=timeapi

all: buildd builds

buildd: main.c clean
	$(CC) main.c -l$(LIB) -o mainD -I. -L./module

builds: main.c clean
	$(CC) -static  main.c -o mainS -l$(LIB) -L./module -I.


clean: 
	#rm -f mainD mainS
