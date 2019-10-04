#include <stdio.h>

long long int fatorial(long long int n)
{
	long long int k;

	for(k=1; n>0; n--)
		k = k*n;

	return k;
}

int main()
{
	long long int m, n;

	while(scanf("%lli %lli", &m, &n) != EOF)
	{
		m = fatorial(m);
		n = fatorial(n);

		printf("%lli\n", m + n);
	}

	return 0;
}