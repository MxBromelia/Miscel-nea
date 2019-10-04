#include <stdio.h>
#include <string.h>

int sentenceCheck(const char* operation)
{
	int i;
	int len = strlen(operation);
	int brackets = 0;

	for(i=0;i<len;i++)
	{
		if(operation[i] == '(')
			brackets++;
			else
				if(operation[i] == ')')
				{
					brackets--;

					if(brackets<0)
						return 0;
				}
	}

	if(brackets != 0)
		return 0;

	return 1;
}

int main()
{
	char expressao[1001];

	while(scanf("%s", expressao) != EOF)
	{
		if(sentenceCheck(expressao))
			printf("correct\n");
		else
			printf("incorrect\n");
	}

	return 0;
}