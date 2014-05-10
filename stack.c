#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//push f onto stack
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full; can't push %g.\n", f);
}

//return top of stack
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}