CC=gcc
CXXFLAGS= -Wall -Wvla  -Werror -Wextra -g -std=c99


%.o : %.c


main: main.o rsa.o modulo.o
	gcc modulo.o rsa.o main.o -o main

main.o: main.c rsa.c modulo.c
	gcc -c $(CXXFLAGS) main.c

rsa.o: rsa.c rsa.h modulo.c modulo.h
	gcc -c $(CXXFLAGS) rsa.c

modulo.o: modulo.c modulo.h
	gcc -c $(CXXFLAGS) modulo.c

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf main







