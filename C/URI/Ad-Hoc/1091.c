#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} coord;

int main()
{
	int times;
	int i;

	coord divisa;
	coord* coords;

	while(scanf("%d", &times), times != 0)
	{
		scanf("%d %d", &divisa.x, &divisa.y);
		coords = (coord*)malloc(sizeof(coord)*times);

		for(i=0;i<times;i++)
			scanf("%d %d", &coords[i].x, &coords[i].y);

		for(i=0;i<times;i++)
			if(coords[i].x == divisa.x || coords[i].y == divisa.y)
				printf("divisa\n");
			else
				if(coords[i].x > divisa.x)
				{
					if(coords[i].y > divisa.y)
						printf("NE\n");
					else
						printf("SE\n");
				}
				else
				{
					if(coords[i].y > divisa.y)
						printf("NO\n");
					else
						printf("SO\n");
				}

		free(coords);
	}

	return 0;
}