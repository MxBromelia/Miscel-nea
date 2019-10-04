#include <stdio.h>
#include <stdlib.h>

#define LEN 5

void vetor(int **v)
{
	printf("%d %d %d\n", sizeof(v), sizeof(*v), sizeof(**v));
}

int main()
{
	int *v;

	v = (int*) malloc(sizeof(int)*LEN);

	printf("%d %d %d\n", sizeof(&v), sizeof(v), sizeof(*v));

	vetor(&v);

	return 0;
}