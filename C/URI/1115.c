#include <stdio.h>

int main()
{
	int x;
	int y;

	while(scanf("%d %d", &x, &y), x != 0 && y != 0)
	{
		if(y > 0)
		{
			if(x > 0)
				printf("primeiro\n");
			else
				printf("segundo\n");
		}
		else
		{
			if(x < 0)
				printf("terceiro\n");
			else
				printf("quarto\n");
		}
	}

	return 0;
}