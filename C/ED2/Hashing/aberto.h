#ifndef HASHABERTO_H
#define HASHABERTO_H

#define MAX(A,B) ((A>B) ? (A) : (B))

typedef char* string;

typedef struct
{
	string content;
	int id;
} Row;

typedef struct cl
{
	Row row;
	struct cl* next;
}Cel;

typedef struct
{
	int len;
	int lf;
	
	Cel **rows;
} Table;

int generateId(string content);
int hashFunction(int id, int tableLen);
Row newRow(string content);
Cel newCel(Row row);
Table newTable(int len);
void addValue(Table *t, Row toAdd);
void rmvValue(Table *t, int key);
void printTable(Table *t);

#endif
