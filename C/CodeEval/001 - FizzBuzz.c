#include <stdio.h>

int main()
{
	int x,y,n;
	int i;


	while(scanf("%d %d %d", &x, &y, &n) != EOF)
	{
		for(i=1;i<=n;i++)
		{
			if(i % x)
			{
				if(i % y)
					printf("%d ", i);
				else
					printf("B ");
			}
			else
				if(i % y)
					printf("F ");
				else
					printf("FB ");
		}
		printf("\n");
	}

	return 0;
}