#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define NUM 10

#define SWAP(a,b) int x = a; a = b; b = x

void create_vector(int **v, int n)
{
	srand((unsigned)time(NULL));

	*v = (int*) malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		*v[i] = rand() % MAX;
}

void print_vector(int* v, int n)
{
	for(int i = 0; i < n; i++)
		printf("%4d\t", v[i]);
	printf("\n");
}

void bubbleSort(int* ord, int n)
{
	int i, j;
	int aux;

	for(i = 0; i < n; i++)
	{
		for(j=i+1; j< n; j++)
		{
			if(ord[i] > ord[j])
			{
				SWAP(ord[i], ord[j]);
			}
		}
	}
}

int main()
{
	int* vec;
	int num = NUM;

	printf("Hello World!\n");
	/*create_vector(&vec, num);

	print_vector(vec, num);
	bubbleSort(vec, num);
	print_vector(vec, num);*/

	return 0;
}