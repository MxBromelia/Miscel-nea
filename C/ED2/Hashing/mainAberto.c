#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"aberto.h"

int main()
{
	int len;
	int i;
	string s = (string)malloc(sizeof(char)*32);
	Table *t = (Table*)malloc(sizeof(Table));

	printf("Tamanho:");
	scanf("%d", &len);
	
	*t = newTable(len);

	printTable(t);

	do
	{
		
		printf("Nome:");
		scanf("%s", s);

		if(strcmp(s,"END"))
		{
			addValue(t, newRow(s));
			printTable(t);
		}
	}
	while(strcmp(s,"END"));

	do
	{
		
		printf("Key:");
		scanf("%d", &i);

		if(i != -1)
		{
			rmvValue(t, i);
			printTable(t);
		}
	}
	while(i != -1);

	return 0;
}
