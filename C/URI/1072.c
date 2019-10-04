#include <stdio.h>

int main()
{
	int n;
	int number;
	int in = 0;
	int out = 0;

	scanf("%d", &n);

	while(n>0)
	{
		scanf("%d", &number);

		if((unsigned) number - 10 <= 10)
			in++;
		else
			out++;

		n--;
	}

	printf("%d in\n%d out\n", in, out);

	return 0;
}