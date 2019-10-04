#ifndef HASHABERTOAVL_H
#define HASHABERTOAVL_H

#include"avl.h"

#define MAX(A,B) ((A>B) ? (A):(B))

typedef struct
{
	int len;
	int lf;
	
	Knot **rows;
} Table;

int hashFunction(int id, int tableLen);
Table newTable(int len);
void addValue(Table *t, int toAdd);
void rmvValue(Table *t, int key);
void printTable(Table *t);

#endif
