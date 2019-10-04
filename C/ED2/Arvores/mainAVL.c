#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int id;
	Knot *root = malloc(sizeof(Knot));
	root = NULL;
	
	do
	{
		printf("No:");
		scanf("%d", &id);

	    if(id >= 0)
			addKnot(&root, newContent(id));
		else
			rmvKnot(&root, newContent(-id));
		printf("\n##############################\n");
		mostrar_arvore(root, 0);
		printf("\nAltura: %d",height(root));
		printf("\n##############################\n");
	}
	while(id!=0);
	//addFromFile(&root, "ordem");
	printf("\n");
	
	return 0;
}
