all: calc

calc: calc.o
	gcc -o calc main.o stack.o getop.o -lm -g

calc.o: main.c stack.c getch.c getop.c
	gcc -c main.c stack.c getop.c -lm -g

clean:
	rm calc.o calc
