CC=g++ 
OFLAGS=-o -c
PFLAGS=-o
OBJPATH=./obj/

default: d1

d1: my.o use.o
	@$(CC) $(PFLAGS) d1 $(OBJPATH)my.o $(OBJPATH)use.o

my.o: my.cpp my.h
	@$(CC) -o $(OBJPATH)my.o -c my.cpp

use.o: use.cpp my.h
	@$(CC) -o $(OBJPATH)use.o -c use.cpp

.PHONY: clean

clean:
	@rm $(OBJPATH)*.o; rm d1
