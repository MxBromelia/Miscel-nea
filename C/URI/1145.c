#include <stdio.h>

int main()
{
	int col;
	int num;

	int i;
	int j;

	scanf("%d %d", &col, &num);

	for(i=1;i<=num;)
	{
		for(j=0;j<col && i<=num;j++, i++, printf(" "))
			printf("%d", i);
		printf("\n");
	}

	return 0;
}