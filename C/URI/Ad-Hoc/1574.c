#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT -1
#define RIGHT 1
#define SAME_AS(i) insts[i]

int main()
{
	char buffer[15];

	int pos;
	int* insts;

	int cases;
	int nInst;

	int i;

	scanf("%d", &cases);

	while(cases>0)
	{
		pos = 0;
		scanf("%d", &nInst);
		insts = (int*)malloc(sizeof(int)*nInst);

		for(i=0;i<nInst;i++)
		{
			scanf("%s", buffer);

			if(! strcmp(buffer, "LEFT"))
				insts[i] = LEFT;
			else
				if(! strcmp(buffer, "RIGHT"))
					insts[i] = RIGHT;
				else
					if(! strcmp(buffer, "SAME AS "))
					{
						memmove(buffer, buffer+8, 4);

						insts[i] = SAME_AS(atoi(buffer));
					}
					else
						printf("buffer:%15s\n", buffer);
			pos = pos + insts[i];
			fflush(stdin);
		}
		printf("%d\n", pos);

		free(insts);
		cases--;
	}

	return 0;
}