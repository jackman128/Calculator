#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
 
#define NUMBER '0'
#define MAXVAL 100

void push(double);
double pop(void);
int getop(char []);
void clear(void);
double top(void);
void duplicate(void);
void swap(void);
void empty(void);
