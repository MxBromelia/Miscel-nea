#include <stdio.h>

int main()
{
	int num;

	scanf("%d", &num);

	if(num % 2 == 0)
		num++;

	printf("%d\n%d\n%d\n%d\n%d\n%d\n", num, num+2, num+4, num+6, num+8, num+10);

	return 0;
}