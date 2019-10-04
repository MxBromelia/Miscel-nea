#include <stdio.h>
#include <stdlib.h>

int main()
{
	int len;
	int *amp;
	int peaks;

	int i;

	scanf("%d", &len);

	while(len != 0)
	{
		amp = (int*)malloc(sizeof(int)*len);
		peaks = 0;

		for(i=0;i<len;i++)
			scanf("%d", &amp[i]);

		for(i=0;i<len;i++)
			if((amp[(len+i-1)% len] > amp[i] && amp[(i+1) % len] > amp[i]) || (amp[(len+i-1)% len] < amp[i] && amp[(i+1) % len] < amp[i]))
				peaks++;

		printf("%d\n", peaks);

		free(amp);
		scanf("%d", &len);
	}

	return 0;
}