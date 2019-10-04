#include <stdio.h>

int main()
{
	int num;
	int i;

	int maior;
	int pos;

	for(i=1, maior = 0;i<=100;i++)
	{
		scanf("%d", &num);

		if(num > maior)
		{
			maior = num;
			pos = i;
		}
	}

	printf("%d\n", maior	);
	printf("%d\n", pos);

	return 0;
}