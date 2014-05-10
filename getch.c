#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

//push character back into input
void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters.\n");
	else
		buf[bufp++] = c;
}
