#include <stdio.h>

int main()
{
	unsigned int opA;
	unsigned int opB;

	while(scanf("%d %d", &opA, &opB) != EOF)
	{
		printf("%d\n", (unsigned)(opA | opB) - (opA & opB));
	}

	return 0;
}