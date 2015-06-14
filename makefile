all: Calculator

Calculator: main.o stack.o getop.o 
	gcc -o Calculator main.o stack.o getop.o -lm -O2 -Wall

main.o: main.c
	gcc -c main.c -lm -O2 -Wall

getch.o: getch.c
	gcc -c getch.c -lm -O2 -Wall

stack.o: stack.c
	gcc -c stack.c -lm -O2 -Wall

clean:
	rm *.o Calculator
