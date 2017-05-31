CC=gcc
LIB=timeapi
SHLIB=lib$(LIB).so
STATLIB=lib$(LIB).a

all: statlib shlib

statlib: modules
	ar rcs $(STATLIB) timeLib.o 

shlib: modules
	$(CC) -shared -fPIC -o $(SHLIB) timeLib.o 

modules: clean
	$(CC) -fPIC -c timeLib.c 

clean:
	rm -f *.o
