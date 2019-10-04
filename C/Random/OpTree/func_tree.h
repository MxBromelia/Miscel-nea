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

// Função
typedef struct
{
	char* label; //Nome Ex.: Em f(x) = x+1, label = "f"
	char** varmap; //Variáveis Ex.: Em f(x) = x+1, varmap = {"x"}.

	int varCount; // Número de Variáveis Ex.: Em f(x) = x+1, varCount = 1

	Operation* op; // Valor Ex.: Em f(x) = x, op = x + 1
}
Function;

// Uma operação da string fora de parênteses
typedef struct
{
	int index; //Posição da operação na string
	int priority; //Prioridade do operador
}
Op;

// Lista de operações fora de parênteses na string
typedef struct
{
	Op* content; //Lista
	int size; //Tamanho da lista
}
OpList;

// Informações quanto às operações na string
typedef struct
{
	int menorP; // A menor prioridade na string fora dos parênteses
	int qtdP; //

	OpList op; // Lista de operações
}
Info;

Operation* newOpTree(const char* operation);
Function* mFunction(const char* sentence);

#endif