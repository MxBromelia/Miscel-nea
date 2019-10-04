#include <stdio.h>

int main()
{
	int x1, y1;
	int x2, y2;

	int dx, dy;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	//while(x1 + x2 + y1 + y2 != 0)
	while(x1 != 0 || x2 != 0 || y1 != 0 || y2!=0)
	{
		dx = x1 - x2;
		dy = y1 - y2;

		if(dx*dy == 0)
		{
			if(dx == 0 && dy == 0)
				printf("0\n");
			else
				printf("1\n");
		}
		else
		{
			if(dy/dx == 1 || dy/dx == -1)
				printf("1\n");
			else
				printf("2\n");
		}

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}

	return 0;
}