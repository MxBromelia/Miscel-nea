#include <stdio.h>

int main()
{
	int num;
	int i;

	scanf("%d", &num);

	for(i=1;i<=num;i=i+2)
		printf("%d\n", i);

	return 0;
}