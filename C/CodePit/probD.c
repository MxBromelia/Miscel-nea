#include <stdio.h>

int main()
{
	int X;
	int i;

	for(i=0;i<10;i++)
	{
		scanf("%d", &X);
		if(X <= 0)
			X = 1;
		printf("X[%d] = %d\n", i, X);
	}

	return 0;
}