#include "calc.h"

#define MAXOP 100

void help(void);

int main() {
	int type;
	double op2;
	char s[MAXOP];
	double last;
	int status = 0;
	
	help();
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			//Commands
			case 'A':
				printf("%g\n", top());
				break;
			case 'B':
				swap();
				printf("Top two values swapped.\n");
				break;
			case 'C':
				clear();
				printf("Stack cleared.\n");
				break;
			case 'D':
				duplicate();
				printf("Top value duplicated.\n");
				break;
			case 'P':
				printf("%g\n", pop());
				break;
			//math library operators
			case 'S':
				push(sin(pop()));
				status = 1;
				break;
			case 'T':
				push(tan(pop()));
				status = 1;
				break;
			case 'O':
				push(cos(pop()));
				status = 1;
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				status = 1;
				break;
			case 'Q':
				push(sqrt(pop()));
				status = 1;
				break;
			case '|':
				push(fabs(pop()));
				status = 1;
				break;
			//help
			case '?':
				help();
				break;
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				status = 1;
				break;
			case '*':
				push(pop() * pop());
				status = 1;
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				status = 1;
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
					status = 1;
				}
				else
					printf("Error: cannot divide by zero.\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0) {
					push(fmod(pop(), op2));
					status = 1;
				}
				else
					printf("Error: cannot divide by zero.\n");
				break;
			case '\n':
				if (status) {
					printf("\t%.8g\n", pop());
					status = 0;
				}
				break;
			default:
				printf("Error: unkown command.\n");
				break;
		}
	}
	
	return 0;
}

void help(void) {
	printf("\nHELP:\n\n");
	printf("This is a reverse polish calculator. You must use it like so:\n");
	printf("1 + 1 is written as:\n");
	printf("1 1 +\n");
	printf("(1 - 2) * (4 + 5) is written as:\n");
	printf("1 2 - 4 5 + *\n\n");
	printf("COMMANDS:\n\n");
	printf("A\tPrints top of stack.\n");
	printf("B\tSwaps the top two values.\n");
	printf("C\tClear the stack.\n");
	printf("D\tDuplicate the top value.\n");
	printf("P\tPop the stack.\n");
	printf("?\tShow this message.\n\n");
	printf("OPERATORS:\n\n");
	printf("S\tSine\n");
	printf("O\tCosine\n");
	printf("T\tTangent\n");
	printf("^\tPower\n");
	printf("Q\tSquare root\n\n");
}