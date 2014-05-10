#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
 
#define NUMBER '0'

double push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void clear(void);
double top(void);
void duplicate(void);
void swap(void);