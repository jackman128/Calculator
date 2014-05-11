#include "calc.h"

int sp = 0;
double val[MAXVAL];

//push f onto stack
double push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full; can't push %g.\n", f);
}

//return top of stack
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else
		return 0.0;
}

//clear the stack
void clear(void) {
	sp = 0;
}
//return top of stack
double top(void) {
	return val[sp - 1];
}
//duplicate top value
void duplicate(void) {
	push(val[sp - 1]);
}
//swap top 2 values
void swap(void) {
	double swap1;
	double swap2;
	swap1 = pop();
	swap2 = pop();
	push(swap1);
	push(swap2);
}
//dump the stack
void empty(void) {
	while (sp != 0)
		printf("%g\n", pop());
}