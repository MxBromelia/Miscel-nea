#include "func_tree.h"
#include <stdlib.h>
#include <string.h>

//temp
#include <stdio.h>

#define TRUE !0
#define FALSE 0

const char ops[] = {'+','-','*','/','^','^','(',')','\0'};	//Array contendo os operadores binários possíveis

/*
TO-DO List:

FN_MT.3
	Se há apenas um parêntese, checar se é um bloco de operações entre parênteses ou uma função
		- Se for um bloco, montar um árvore com o que há dentro do bloco
		- Se for uma função, (...)

*/

OpList newOpList(int size)
{
	OpList ret;

	ret.content = (Op*)malloc(sizeof(Op)*size);
	ret.size = 0;

	return ret;
}

Function newFunction(char* function)
{
	Function f;

	int i;
	int len;
	char* ptr;
	char* ptrr;

	f.varCount = 1;

	ptr = strchr(function, '(');
	*ptr = '|';
	while( (ptr = strchr(ptr+1, ','))!= NULL)
	{
		*ptr = '|';
		f.varCount++;
	}
	ptr = strchr(function, ')');
	*ptr = '|';

	ptr = strchr(function, '|');
	len = ptr-function;
	f.label = (char*)malloc(sizeof(char)*(len+1));
	strncpy(f.label, function, len);
	f.label[len]='\0';

	f.varmap = (char**)malloc(sizeof(char*)*(f.varCount));

	ptr = ptr+1;
	for(i=0, ptrr = strchr(ptr, '|'); ptrr != NULL; ptrr = strchr(ptr+1, '|'),i++)
	{
		len = ptrr-ptr;
		f.varmap[i] = (char*)malloc(sizeof(char)*(len+1));
		strncpy(f.varmap[i], ptr, len);
		f.varmap[i][len] = '\0';

		ptr = ptrr+1;
	}
	
	return f;
}

int sentenceCheck(const char* operation)
{
	int i;
	int len = strlen(operation);
	int brackets = 0;

	for(i=0;i<len;i++)
	{
		if(operation[i] == '(')
			brackets++;
			else
				if(operation[i] == ')')
				{
					brackets--;

					if(brackets<0)
						return FALSE;
				}
	}

	if(brackets != 0)
		return FALSE;

	return TRUE;
}

OpList getOpList(const char* sentence, int len)
{
	int i;
	int brackets = 0;
	char* pivot;

	OpList oplist = newOpList(len/2);

	for(i=0;i<len;i++)
	{
		pivot = strchr(ops, sentence[i]);
		if(( pivot != NULL) && (brackets == 0))
		{
			oplist.content[oplist.size].index = i;
			//oplist.content[oplist.size].priority = (pivot-ops)/2;
			oplist.content[oplist.size].priority = (pivot-ops);
			oplist.size++;
		}

		if(sentence[i] == '(')
			brackets++;
		else
			if(sentence[i] == ')')
				brackets--;
	}

	return oplist;
}


//Label: FN_MT
Operation* mTree(const char* sentence, int len)
{
	Operation* ret;
	int i;
	int k;
	int medio;
	int menor;

	/*for(i=0;i<len;i++)
		printf("%c", sentence[i]);
	printf("\n");*/

	OpList oplist = getOpList(sentence, len);

	//Label: FN_MT.1
	//Se a entrada é um literal, retorne-o.
	if(oplist.size == 0)
	{
		ret = (Operation*)malloc(sizeof(Operation));
		ret->content = (char*)malloc(sizeof(len+1));
		strncpy(ret->content, sentence, len);
		ret->content[len] = '\0';
		ret->left = NULL;
		ret->right = NULL;

		return ret;
	}

	//Label: FN_MT.2
	//Caso não seja, descubra se há operações
	for(i=1, menor = oplist.content[0].priority; i<oplist.size && menor > 0;i++)
	{
		if(oplist.content[i].priority < menor)
			menor = oplist.content[i].priority;
	}

	//Label: FN_MT.3
	//Se há apenas um bloco, entre parênteses, monte a sub-árvore de dentro dos parênteses
	if(menor == 6)
		return mTree(sentence+1, len-2);
	
	//Labe: FN_MT.4
	//Se há ao menos uma operação, descubra a quantidade da de menor prioridade
	for(i=0, k=0; i<oplist.size; i++)
		if(oplist.content[i].priority == menor)
		{
			oplist.content[k] = oplist.content[i];
			k++;
		}
	oplist.size = k;

	//Separe a entrada na operação central de menor prioridade
	//medio = oplist.content[oplist.size/2].index;
	medio = oplist.content[oplist.size-1].index;

	ret = (Operation*)malloc(sizeof(Operation));
	ret->content = (char*)malloc(sizeof(char)*2);
	ret->content[0] = sentence[medio];
	ret->content[1] = '\0';
	ret->left = mTree(sentence, medio);
	ret->right = mTree(sentence+medio+1, len-medio-1);

	return ret;
}

Operation* newOpTree(const char* operation)
{
	Operation *ret;

	if(sentenceCheck(operation) == FALSE)
		return NULL;

	ret = mTree(operation, strlen(operation));

	return ret;
}

int operationCheck(Operation* op, char** varmap, int varCount)
{
	if(strchr(ops, op->content[0]))
		return operationCheck(op->left, varmap, varCount) & operationCheck(op->right, varmap, varCount);

	;

	return TRUE;
}

int functionCheck(Function* f)
{
	if(f!=NULL)
		return operationCheck(f->op, (*f).varmap, f->varCount);
	return FALSE;
}

Function* mFunction(const char* sentence)
{
	char* equality;
	char* fDeclaration;
	int len;
	Function* f = (Function*)malloc(sizeof(Function));

	equality = strchr(sentence, '=');

	if(equality == NULL)
		return NULL;
	len = equality-sentence;

	fDeclaration = (char*)malloc(sizeof(char)*(len+1));
	strncpy(fDeclaration, sentence, len);
	fDeclaration[len] = '\0';

	*f = newFunction(fDeclaration);
	f->op = newOpTree(equality+1);

	if(functionCheck(f) == FALSE)
		return NULL;

	return f;
}

int getOpInfo(char* sentence, int len, Info* info)
{
	int i;
	int j;

	int pvt;

	char* pivot;

	info->op = newOpList(len/2);
	info->menorP = 8;
	info->qtdP = 0;

	for(i=0;i<len;i++)
	{
		pivot = strchr(ops, sentence[i]);
		if(( pivot != NULL) && (brackets == 0))
		{
			pvt = pivot-ops;

			info->op.content[oplist.size].index = i;
			info->op.content[oplist.size].priority = pvt;

			if(pvt == menorP)
				info->qtdP++;
			else if(pvt < menorP)
			{
				info->menorP = pvt;
				info->qtdP = 1;
			}
			info->op.size++;
		}

		if(sentence[i] == '(')
			brackets++;
		else
			if(sentence[i] == ')')
			{
				brackets--;

				if(brackets<0)
					return FALSE;
			}
	}

	return TRUE;
}