#ifndef FUNC_TREE_H
#define FUNC_TREE_H

#define SUM 0
#define SUB 1
#define MLT 2
#define DIV 3
#define PWR 4
#define FNC 5

typedef struct op
{
	char* content;
	
	struct op* left;
	struct op* right;
}
Operation;

typedef struct
{
	char* label;
	char** varmap;

	int varCount;

	Operation* op;
}
Function;

typedef struct
{
	int index;
	int priority;
}
Op;

typedef struct
{
	Op* content;
	int size;
}
OpList;

typedef struct
{
	int menorP;
	int qtdP;

	OpList op;
}
Info;

Operation* newOpTree(const char* operation);
Function* mFunction(const char* sentence);

#endif