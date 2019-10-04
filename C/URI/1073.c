#include <stdio.h>

int main()
{
	int num;
	int i;

	scanf("%d", &num);

	if(num>5 && num<2000)
		for(i=2;i<=num;i+=2)
			printf("%d^2 = %d\n", i, i*i);

	return 0;
}