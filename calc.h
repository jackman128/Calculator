#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
 
#define NUMBER '0'

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);