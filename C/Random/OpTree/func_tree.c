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

mTree
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

// Checa se há consistência na ordem e quantidade de parênteses
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

Operation* mTree(const char* sentence, int len)
{
	Operation* ret;
	int i;
	int k;
	int medio;
	int menor;

	OpList oplist = getOpList(sentence, len);

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

	//Caso não seja, descubra se há operações
	for(i=1, menor = oplist.content[0].priority; i<oplist.size && menor > 0;i++)
	{
		if(oplist.content[i].priority < menor)
			menor = oplist.content[i].priority;
	}

	//Se há apenas um bloco, entre parênteses, monte a sub-árvore de dentro dos parênteses
	if(menor == 6)
		return mTree(sentence+1, len-2);

	//Se há ao menos uma operação, descubra a quantidade da de menor prioridade
	for(i=0, k=0; i<oplist.size; i++)
		if(oplist.content[i].priority == menor)
		{
			oplist.content[k] = oplist.content[i];
			k++;
		}
	oplist.size = k;

	//Separe a entrada na operação central de menor prioridade
	medio = oplist.content[oplist.size/2].index;
	//medio = oplist.content[oplist.size-1].index;

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
	char* opDeclaration;

	int flen;
	int oplen;

	Function* f = (Function*)malloc(sizeof(Function));

	equality = strchr(sentence, '=');

	if(equality == NULL)
		return NULL;
	flen = equality-sentence;
	oplen = strlen(sentence) - flen - 1;

	fDeclaration = (char*)malloc(sizeof(char)*(flen+1));
	strncpy(fDeclaration, sentence, flen);
	fDeclaration[flen] = '\0';

	printf("%s", fDeclaration);

	opDeclaration = (char*)malloc(sizeof(char)*(oplen+1));
	strncpy(opDeclaration, equality+1, oplen);
	opDeclaration[oplen] = '\0';

	printf("%s", opDeclaration);

	*f = newFunction(fDeclaration);

	if(f != NULL)
		f->op = newOpTree(equality+1);

	if(functionCheck(f) == FALSE)
		return NULL;

	return f;
}