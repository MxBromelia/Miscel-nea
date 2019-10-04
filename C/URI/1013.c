#include <stdio.h>

int abs(int a)
{
	return (a>0)?(a):(-a);
}

int maior(int a, int b)
{
	return (a+b+abs(a-b))/2;
}

int main()
{
	int valor[3];
	int m;

	scanf("%d %d %d", &valor[0], &valor[1], &valor[2]);

	m = maior(valor[0], valor[1]);
	m = maior(m, valor[2]);
	
	printf("%d eh o maior\n", m);

	return 0;
}