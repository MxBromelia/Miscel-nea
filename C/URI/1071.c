#include <stdio.h>

int main()
{
	int numA;
	int numB;
	int i;
	int soma = 0;

	scanf("%d %d", &numA, &numB);

	if(numA > numB)
	{
		numA = numA + numB;
		numB = numA - numB;
		numA = numA - numB;
	}

	for(i = (numA % 2)?(numA+2):(numA+1); i < numB; i = i + 2)
		soma = soma + i;
	printf("%d\n", soma);

	return 0;
}