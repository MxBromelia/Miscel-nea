#include <stdio.h>

#define N 3

int main()
{
	int v[N];
	int o[N];

	int i;
	int j;

	int pivo;

	for(i=0;i<N;i++)
	{
		scanf("%d", &o[i]);
		v[i] = o[i];
	}

	for(i=1;i<N;i++)
	{
		pivo = o[i];

		for(j=i-1;j>=0 && pivo < o[j]; j--)
			o[j+1] = o[j];
		o[j+1] = pivo;
	}

	for(i=0;i<N;i++)
		printf("%d\n", o[i]);
	printf("\n");

	for(i=0;i<N;i++)
		printf("%d\n", v[i]);

	return 0;
}