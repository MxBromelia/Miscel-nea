#include"aberto.h"

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(A,B) ((A>B) ? (A) : (B))

int generateId(string content)
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
	r.id = generateId(content);

	return r;
}

Cel newCel(Row row)
{
	Cel c;

	c.row = row;
	c.next = NULL;

	return c;
}

Table newTable(int len)
{
	int i;
	Table t;

	t.rows = (Cel**)malloc(sizeof(Cel*) * len);
	t.len = len;
	t.lf = 0;

	for(i=0;i<len;i++)
		t.rows[i] = NULL;

	return t;
}

int lenList(Cel *fst)
{
	int i;
	Cel *c = fst;
	
	for(i=0; c != NULL;i++)
		c= c->next;

	return i;
}

void addValue(Table *t, Row toAdd)
{
	int key;
	Cel *c;

	c = (Cel*)malloc(sizeof(Cel));
	*c = newCel(toAdd);

	key = hashFunction(toAdd.id, t->len);

	c->next = t->rows[key];
	t->rows[key] = c;

	t->lf = MAX(lenList(t->rows[key]), t->lf);
}

void rmvValue(Table *t, int key)
{
	int i;
	int pos = hashFunction(key, t->len);
	Cel *c1;
	Cel *c2;
	
	c2 = t->rows[pos];

	c1 = c2;

	if((c2->row.id == key) && (c2!= NULL))
	{
		t->rows[pos] = c2->next;
		free(c2);
	}
	else
		while(c2!=NULL)
		{
			if(c2->row.id == key)
			{
				c1->next = (c2)->next;
				free(c2);
				
				break;
			}
		
			c1 = c2;
			c2 = c1->next;
		}

	if(lenList(t->rows[pos]) < t->lf)
		for(i=0, t->lf = 0;i< t->len; i++)
			t->lf = MAX(t->lf, lenList(t->rows[i]));
}

void printTable(Table *t)
{
	int i;
	Cel *c;
	printf("Fator de Carga: %d\n", t->lf);
	for(i=0;i < t->len;i++)
	{
		c = t->rows[i];
		
		if(t->rows[i] == NULL)
			printf("%2d\t--\t-------", i);
		else
		{
			printf("%2d|\t", i);
			while(c != NULL)
			{
				printf("%d\t%s->\t", c->row.id, c->row.content);
				c = c->next;
			}
		}
		printf("\n");
	}
	printf("Fator de Carga: %d\n", t->lf);
}
