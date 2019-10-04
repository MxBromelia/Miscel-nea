#include <stdio.h>
#include "interface.h"

void print_rec(Operation *toPrint, int height)
{
	int i;

	if(toPrint->right != NULL)
		print_rec(toPrint->right, height+1);

	/*for(i=0; i<SPACES*height; i++)
		printf(" ");*/
	for(i=0;i<height;i++)
		printf("\t");
	printf("%s\n", toPrint->content);

	if(toPrint->left != NULL)
		print_rec(toPrint->left, height+1);
}

void print_tree(Operation *toPrint)
{
	if(toPrint!=NULL)
		print_rec(toPrint, 0);
	else
		printf("Arvore Vazia\n");
}

void print_function(Function *toPrint)
{
	int i;

	printf("label:%s\n", toPrint->label);
	printf("vars:\t");
	for(i=0;i< toPrint->varCount; i++)
		printf("%s\t", toPrint->varmap[i]);
	printf("\n");
	printf("Function:\n");
	print_tree(toPrint->op);
}