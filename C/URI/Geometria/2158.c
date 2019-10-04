#include <stdio.h>

int main()
{
	int FP, FH;

	while(1)
	{
		scanf("%d %d", &FP, &FH);
		printf("Possui %d atomos e %d ligacoes\n", (3*FP + 4*FH)/2 + 2, (5*FP + 6*FH)/2);
	}

	return 0;
}