#include<stdio.h>

int main()
{
	long long int m,n;
	int a;

	scanf("%lld %LLd %d", &m, &n, &a);
	printf("%lli\n", ((m/a)+(m%a!=0))*((n/a)+(n%a!=0)));

	return 0;
}