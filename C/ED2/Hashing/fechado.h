#ifndef HASHFECHADO_H
#define HASHFECHADO_H

#define VOID_ROW ' '
#define FILL_ROW '#'
#define MOVE_ROW '*'

#define FAILURE 0
#define SUCESS !0

typedef char* string;

typedef struct
{
	string content;
	char status;
	int key;
} Row;

typedef struct{
	Row* row;

	int len;
} Table;

Row newRow(string content);
Table newTable(int len);

void printTable(Table *t);
int addValue(Table *t, Row toAdd);
int rmvValue(Table *t, int key);

#endif
