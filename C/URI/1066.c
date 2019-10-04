#include <stdio.h>

int main()
{
	int numbers[5];
	int impar = 0;
	int positivo = 0;
	int negativo = 0;

	int i;

	for(i=0;i<5;i++)
	{
		scanf("%d", &numbers[i]);

		if(numbers[i] % 2)
			impar++;
		if(numbers[i] > 0)
			positivo++;
		else
			if(numbers[i]<0)
				negativo++;
	}

	printf("%d valor(es) par(es)\n", 5 - impar);
	printf("%d valor(es) impar(es)\n",impar);
	printf("%d valor(es) positivo(s)\n", positivo);
	printf("%d valor(es) negativo(s)\n", negativo);

	return 0;
}