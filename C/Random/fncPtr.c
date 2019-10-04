#include <stdio.h>

int sum(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mlt(int a, int b)
{
	return a*b;
}

int div(int a, int b)
{
	return a/b;
}

int fnc( int (*a)(int, int), int(*b)(int, int))
{
	return(a(10,b(20,30)));
}

int main()
{
	int (*funcA)(int, int), (*funcB)(int, int);

	funcA = sum;

	funcB = sum;
	printf("sum/sum:%d\n", fnc(funcA,funcB));

	funcB = sub;
	printf("sum/sub:%d\n", fnc(funcA,funcB));

	funcB = mlt;
	printf("sum/mlt:%d\n", fnc(funcA,funcB));

	funcB = div;
	printf("sum/div:%d\n", fnc(funcA,funcB));

	return 0;
}