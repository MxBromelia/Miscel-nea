#include "func_tree.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>

int main()
{
	char buff[128];
	char* newLine;
	Operation *op;
	Function *func;

	scanf(" %s", buff);
	fgets(buff, sizeof(buff), stdin);
	newLine = strchr(buff,'\n');
	if(newLine!= NULL)
		*newLine = '\0';

	if(strchr(buff, '=') == NULL)
	{
		op = newOpTree(buff);
		print_tree(op);
	}
	else
	{
		func = mFunction(buff);
		print_function(func);
	}

	return 0;
}
