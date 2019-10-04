#include <stdio.h>

int main()
{
	int N;
	int i;

	scanf("%d", &i);

	for(N=2; N<10000; N = N + i)
		printf("%d\n", N);

	return 0;
}