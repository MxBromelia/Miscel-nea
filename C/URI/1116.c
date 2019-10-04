#include <stdio.h>

int main()
{
	int cases;

	int dividendo, divisor;

	scanf("%d", &cases);

	while(cases > 0)
	{
		scanf("%d %d", &dividendo, &divisor);

		if(divisor != 0)
			printf("%.1f\n", (float)dividendo/divisor);
		else
			printf("divisao impossivel\n");

		cases--;
	}

	return 0;
}