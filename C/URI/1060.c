#include <stdio.h>

int main()
{
	int i;
	float pivo;
	int count;

	for(i=0, count = 0; i<6;i++)
	{
		scanf("%f", &pivo);

		if(pivo > 0)
			count++;
	}

	printf("%d valores positivos\n", count);

	return 0;
}