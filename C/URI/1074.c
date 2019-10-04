#include <stdio.h>

typedef char* string;

int main()
{
	int trials;
	int number;

	string stat[] = {"EVEN", "ODD"};

	scanf("%d", &trials);

	while(trials>0)
	{
		scanf("%d", &number);

		if(number)
		{
			if(number>0)
				printf("%s POSITIVE\n", stat[(unsigned)number % 2]);
			else
				printf("%s NEGATIVE\n", stat[(unsigned)number % 2]);
		}
		else
			printf("NULL\n");

		trials--;
	}

	return 0;
}