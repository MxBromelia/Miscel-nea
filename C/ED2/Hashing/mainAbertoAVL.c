#include"aberto_avl.h"

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int key;
	int len;
	Table *t = (Table*) malloc(sizeof(Table));

	printf("Tamanho:");
	scanf("%d", &len);
	
	*t = newTable(len);
	printTable(t);

	do
	{
		printf("Chave:");
		scanf("%d", &key);

	    if(key >= 0)
			addValue(t, key);
		else
			rmvValue(t, -key);

		printTable(t);
	}
	while(key!=0);

	return 0;
}