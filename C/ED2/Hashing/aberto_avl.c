#include"aberto_avl.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hashFunction(int id, int tableLen)
{
	return id % tableLen;
}

Table newTable(int len)
{
	int i;
	Table t;

	t.rows = malloc(sizeof(Knot*) * len);
	t.len = len;
	t.lf = 0;

	for(i=0;i<len;i++)
		t.rows[i] = NULL;

	return t;
}

void addValue(Table *t, int toAdd)
{
	int key;

	key = hashFunction(toAdd, t->len);
	addKnot(&t->rows[key], newContent(toAdd));

	t->lf = MAX(height(t->rows[key]), t->lf);
}

void rmvValue(Table *t, int key)
{
	int i;
	int pos = hashFunction(key, t->len);

	rmvKnot(&t->rows[pos], newContent(key));

	if(height(t->rows[pos]) < t->lf)
	{
		for(i=0, t->lf = 0; i< t->len;i++)
			t->lf = MAX(height(t->rows[i]), t->lf);
	}
}

void printTable(Table *t)
{
	int i;
	Knot *k;

	for(i=0;i < t->len;i++)
	{
		k = t->rows[i];

		printf("%d\n", i);
		printf("----------------------------------------\n");
		mostrar_arvore(k, 0);
		printf("\n");
	}
	printf("Fator de Carga: %d\n", t->lf);
}
