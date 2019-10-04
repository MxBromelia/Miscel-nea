#include "function_tree.h"

#include <string.h>

#define OPERATION 'o'
#define FUNCTION 'f'
#define VARIABLE 'v'
#define CONSTANT 'c'

#define SUM '+'
#define DIF '-'
#define MUL '*'
#define DIV '/'
#define EXP '^'

int checkBrackets(string expression)
{
	int i;
	int len = strlen(expression);

	int bracketCount = 0;

	for(i=0;i<len;i++)
	{
		if(expression[i] == ')' && (--bracketCount) < 0)
			return -1;
		else
			if(expression[i] == '(')
				bracketCount++;
	}

	return bracketCount;
}

void mountTree(Function* f, string expression)
{
	if(f == NULL)
		f = (Function*)malloc(sizeof(Function));
}
