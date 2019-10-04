#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char buffer[64];

	srand((unsigned)time(NULL));

	while(1)
	{
		printf("Digite:");
		scanf("%s", buffer);

		printf("%d\n", atoi(buffer)+(rand()%11-5));
	}

	return 0;
}