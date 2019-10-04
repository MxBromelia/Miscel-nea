#include"fechado.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int generateKey(string content)
{
	int i;
	int len = strlen(content);
	int id = 0;

	for(i=0;i<len;i++)
		id = id+(content[i] % 32);

	return id;
}

int hashFunction(int id, int tableLen)
{
	return id % tableLen;
}

Row newRow(string content)
{
	Row r;

	r.content = (string)malloc(sizeof(char)*strlen(content));

	strcpy(r.content, content);
	r.status = FILL_ROW;
	r.key = generateKey(content);

	return r;
}

Row voidRow()
{
	Row r;

	r.content = (string)malloc(sizeof(char));
	r.content = "";
	r.status = VOID_ROW;
	r.key = 0;

	return r;
}

Table newTable(int len)
{
	int i;
	Table t;

	t.row = (Row*)malloc(sizeof(Row*)*len);
	t.len = len;

	for(i=0;i<len;i++)
		t.row[i] = voidRow();

	return t;
}

void printTable(Table *t)
{
	int i;
	Row r;

	printf("Pos\tKey\tStatus\tContent\n");
	for(i=0;i<t->len;i++)
	{
		r = t->row[i];

		if(r.status != VOID_ROW)
			printf("%2d\t%d\t%c\t%s\n", i, r.key, r.status, r.content);
		else
			printf("%2d\t--\t--\t--\n", i);
	}
	printf("Fim da Tabela\n");
}

int addValue(Table *t, Row toAdd)
{
	int key = hashFunction(toAdd.key, t->len);
	int tries = 0;

	if(t->row[key].status != VOID_ROW)
		toAdd.status = MOVE_ROW;

	while(t->row[key].status != VOID_ROW)
	{
		key = (key+1) % t->len;
		tries++;

		if(tries == t->len)
			return FAILURE;
	}
	
	t->row[key] = toAdd;
	return SUCESS;
}

int rmvValue(Table *t, int toRmv)
{
	int pivot;
	int key = hashFunction(toRmv, t->len);
	int tries = 0;

	while(t->row[key].key != toRmv)
	{
		key = (key+1) % t->len;
		tries++;

		if(tries == t->len)
			return FAILURE;
	}

	t->row[key] = voidRow();

	tries = 0;
	pivot = key;

	do
	{
		if(t->row[key].status == MOVE_ROW)
		{
			t->row[pivot] = t->row[key];
			t->row[key] = voidRow();

			if(t->row[pivot].key == hashFunction(key, t->len))
				t->row[pivot].status = FILL_ROW;

			pivot = key;
		}
		key = (key+1) % t->len;
		tries++;
	}
	while(t->len > tries && t->row[key].status != VOID_ROW);
	
	return SUCESS;
}
