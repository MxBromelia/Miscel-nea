#include <stdio.h>

int main()
{
	int i;
	char base32[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	unsigned long int num;

	while(scanf("%lu", &num), num != 0)
	{
		for(i=0; i<64; i = i+5, num = num >> 5)
			printf("%c", base32[num % 32]);
		printf("\n");
	}

	return 0;
}