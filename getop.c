#include "calc.h"

int li = 0;
char line[MAXVAL];

//get next operator or operand
int getop(char s[]) {
	int i, c;
	
	if (line[li] == '\0')
		if (fgets(line, MAXVAL, stdin) == 0)
			return EOF;
		else
			li = 0;
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; //not a number
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;

	return NUMBER;

}
