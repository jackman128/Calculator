#include "calc.h"

#define MAXOP 100

void help(void);

int main() {
	int type = 0;
	int last = 0;
	int i;
	double op2;
	char s[MAXOP];
	double $ = 0;
	double variable[25];
	int status = 0;
	
	help();
	
	for (i = 0; i < 26; i++)
		variable[i] = 0;
	
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
			case 'E':
				empty();
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
			//variables
			case '$':
				push($);
				break;
			case '=':
				pop();
				if (islower(last)) {
					push(variable[last - 'a'] = pop());
					printf("%c set to %g.\n", last, variable[last - 'a']);
				}
				else
					printf("Invalid variable name.\n");
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
					printf("\t%.8g\n", $ = pop());
					status = 0;
				}
				break;
			default:
				if (type >= 'a' && type <= 'z')
					push(variable[type - 'a']);
				else
					printf("Error: unkown command.\n");
				break;
		}
		last = type;
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
	printf("E\tEmpty the stack into the terminal.\n");
	printf("?\tShow this message.\n\n");
	printf("OPERATORS:\n\n");
	printf("S\tSine\n");
	printf("O\tCosine\n");
	printf("T\tTangent\n");
	printf("^\tPower\n");
	printf("Q\tSquare root\n\n");
	printf("VARIABLES:\n\n");
	printf("$ is a variable for the last printed value.\n");
	printf("Otherwise, you can assign any lowercase letter to be a variable.\n");
	printf("To assign a variable, you must use the = operator like so:\n");
	printf("42 n =\n");
	printf("That assigns 42 to the variable n.\n");
	printf("\n");
}
