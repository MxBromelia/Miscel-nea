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
	int N;
	char expressao[1001];

	scanf("%d", &N);

	while(N>0)
	{
		fgets(expressao, 1001, stdin);

		if(sentenceCheck(expressao))
			printf("correct\n");
		else
			printf("incorrect\n");

		N--;
	}

	return 0;
}