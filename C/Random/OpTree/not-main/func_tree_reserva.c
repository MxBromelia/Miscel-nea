#include "func_tree.h"
#include <stdlib.h>
#include <string.h>

//temp
#include <stdio.h>

#define TRUE !0
#define FALSE 0

const char ops[] = {'+','-','*','/','^','(',')','\0'};

//temp
void printSubString(const char* string, int len)
{
	int i;

	for(i=0;i<len;i++)
		printf("%c", string[i]);
}
//temp

int sentenceCheck(const char* operation)
{
	int i;
	int len = strlen(operation);
	int brackets = 0;

	if(operation[0] != '(' || operation[len-1])
		return FALSE;

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

Operation* binaryToTree(const char* operation)
{
	int i;

	int init, len;

	Operation *ret, *left, *right;

	ret = malloc(sizeof(Operation));
	left = malloc(sizeof(Operation));
	right = malloc(sizeof(Operation));

	ret->left = left;
	ret->right = right;

	left->left = NULL;
	left->right = NULL;
	right->left = NULL;
	right->right = NULL;

	for(i=init=0; operation[i] != '\0' && strchr(ops, operation[i]) == NULL; i++);

	len = i-init+1;
	
	if(len != strlen(operation))
	{
		left->content = (char*)malloc(sizeof(char)*len);
		strncpy(left->content, operation, len);
		left->content[len-1] = '\0';
		
		ret->content = (char*)malloc(sizeof(char)*2);
		ret->content[0] = operation[i];
		ret->content[1] = '\0';

		init = i+1;
		len = strlen(operation)-init+1;

		right->content = (char*)malloc(sizeof(char)*len);
		strncpy(right->content, operation+init, len);
		right->content[len-1] = '\0';
	}
	else
	{
		left->content = (char*)malloc(sizeof(char)*2);
		left->content[0] = '0';
		left->content[1] = '\0';

		right->content = (char*)malloc(sizeof(char)*len);
		strcpy(right->content, operation);
	}

	return ret;
}

Operation* mTree(const char* sentence, int len)
{
	Operation* ret;
	int i;
	int j;
	int k;

	char* pivot;

	int medio;

	int brackets = 0;
	int menor;

	OpList* oplist = (OpList*)malloc(sizeof(OpList)*(len/2));

	//temp
	for(i=0;i<len;i++)
		printf("%c", sentence[i]);
	printf("\n");
	//temp

	for(i=0, j=0;i<len;i++)
	{
		pivot = strchr(ops, sentence[i]);
		if((pivot != NULL) && (brackets == 0))
		{
			oplist[j].index = i;
			oplist[j].priority = (pivot-ops)/2;
			j++;
		}

		if(sentence[i] == '(')
			brackets++;
		else
			if(sentence[i] == ')')
				brackets--;
	}

	if(j == 0)
	{
		ret = (Operation*)malloc(sizeof(Operation));
		ret->content = (char*)malloc(sizeof(len+1));
		strncpy(ret->content, sentence, len);
		ret->content[len] = '\0';
		ret->left = NULL;
		ret->right = NULL;

		return ret;
	}

	for(i=0, menor = 4;i<j && menor > 0;i++)
	{
		if(oplist[i].priority < menor)
			menor = oplist[i].priority;
	}

	if(menor == 4)
		return mTree(sentence+1, len-2);
	
	for(i=0, k=0; i<j; i++)
		if(oplist[i].priority == menor)
		{
			oplist[k] = oplist[i];
			k++;
		}
	j = k;

	medio = oplist[j/2].index;

	ret = (Operation*)malloc(sizeof(Operation));
	ret->content = (char*)malloc(sizeof(char)*2);
	ret->content[0] = sentence[medio];
	ret->content[1] = '\0';
	ret->left = mTree(sentence, medio);
	ret->right = mTree(sentence+medio+1, len-medio-1);

	return ret;
}

Operation* mountTree(const char* operation)
{
	Operation* ret;

	int i;
	int j;
	int init, len;

	int brackets;

	char* sentence;

	ret = (Operation*)malloc(sizeof(Operation));

	i = init = 1;
	brackets = 1;
	while(brackets != 0)
	{
		i++;
		if(operation[i] == '(')
			brackets++;
		else
			if(operation[i] == ')')
				brackets--;
	}
	len = i - init + (operation[init] == '(');

	ret->content = (char*)malloc(sizeof(char)*2);
	ret->content[0] = operation[i+1];
	ret->content[1] = '\0';

	sentence = (char*)malloc(sizeof(char)*len);
	strncpy(sentence, operation+init, len);
	//memcpy(sentence, operation+init, len);

	if(operation[init] == '(')
		ret->left = mountTree(sentence);
	else
		return binaryToTree(sentence);

	free(sentence);

	i = init = i+2;
	brackets = 1;
	while(brackets != 0)
	{
		i++;
			if(operation[i] == '(')
			brackets++;
		else
			if(operation[i] == ')')
				brackets--;
		
	}
	len = i-init+(operation[init] == '(');

	sentence = (char*)malloc(sizeof(char)*len);
	strncpy(sentence, operation+init, len);
	//memcpy(sentence, operation+init, len);

	if(operation[init] == '(')
		ret->right = mountTree(sentence);
	else
		binaryToTree(sentence);

	

	free(sentence);

	return ret;
}

Operation* newOpTree(const char* operation)
{
	Operation *ret;

	if(sentenceCheck(operation))
		return NULL;

	//ret = mountTree(operation);
	ret = mTree(operation, strlen(operation));

	return ret;
}