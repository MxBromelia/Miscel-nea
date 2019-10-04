#include <stdio.h>

int main()
{
	int num;
	int aculm;
	int i;

	scanf("%d", &num);

	for(i=1, aculm = num;i<=10;i++, aculm = aculm + num)
		printf("%d x %d = %d\n", i, num, aculm);

	return 0;
}