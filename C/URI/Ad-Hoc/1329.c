#include <stdio.h>
#include <stdlib.h>

int main()
{
	int timesPlayed;
	int* won;

	int Mary = 0;
	int John = 0;

	while(scanf("%d", &timesPlayed), timesPlayed != 0)
	{
		won = (int*) malloc(sizeof(int)*timesPlayed);

		while((timesPlayed--) > 0)
		{
			scanf("%d", &won[timesPlayed]);

			if(won[timesPlayed] == 1)
				John++;
			else
				Mary++;
		}

		printf("Mary won %d times and John won %d times\n", Mary, John);

		Mary = 0;
		John = 0;
		free(won);
	}

	return 0;
}