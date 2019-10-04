#include"fechado.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
	int len;
	int key;
	string nome = (string)malloc(sizeof(char)*32);
	Table *t = (Table*)malloc(sizeof(Table));

	printf("tamanho:");
	scanf("%d", &len);

	*t = newTable(len);

	printTable(t);

	do
	{
		printf("Nome: ");
		scanf("%s", nome);

		if(strcmp(nome,"end"))
			addValue(t, newRow(nome));
		
		printTable(t);
	}
	while(strcmp(nome,"end"));

	do
	{
		printf("Key: ");
		scanf("%d", &key);

		if(key != -1)
			rmvValue(t, key);
		
		printTable(t);
	}
	while(key != -1);

	return 0;

	return 0;
}