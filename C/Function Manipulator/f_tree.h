#ifndef F_TREE
#define F_TREE

#include <stdlib.h>
#include <string.h>

//Estruturas

typedef struct
{
	char* cnt;

	void* left;
	void* right;
} Opt; //Nó de Operador

typedef struct
{
	char* name;
	char** var;

	int nVar;

	Opt* func;
} Fnc; //Nó de Função

//Funções

//Funções de Instânceamento
Opt newOpt(const char*);
Fnc newFnc(const char*, int, char**);

//Funções de Atribuição
Opt* mOpt(const char*, unsigned int);	//Recebe: string da expressão e o tamanho da substring	Envia: Uma árvore de Operations equivalente
Fnc* mFnc(const char*, unsigned int);	//Recebe: string do instânceamento da função e o tamanho da substring	Envia: Uma Function equivalente
Fnc* mTree(const char*, unsigned int);	//Recebe: string da função e o tamanho da string	Envia: Uma Function equivalente que aponta para uma árvore de Operations equivalentes

#endif