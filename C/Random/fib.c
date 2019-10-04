#include <stdio.h>

int main(){
	int ant=0;
	int atual=1;
	int prox=0;
	int termo;
	int i;

	printf("Digite o o termo de fibonnaci desejado");
	scanf("%d",&termo );

	for(i=0; i<termo; i++)
	{
		prox = ant + atual;
		ant=atual;
		atual=prox;
	}

	printf("%d",ant);

	return 0;
}