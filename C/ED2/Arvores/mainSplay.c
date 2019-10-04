#include "splay.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	char command = 'x';
	int id;

	Knot *root = NULL;

	while(command != 'e')
	{
		printf("comando:");
		scanf("%c", &command);
		scanf("%d", &id);
		getchar();

		if(command == 'i')
			addKnot(&root, id);
		else
			if(command == 'r')
				rmvKnot(&root, id);
			else
				if(command == 's')
					splay(&root, id);


		printf("##################################################\n");
		printTree(root);
	}

	return 0;
}