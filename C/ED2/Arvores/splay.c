#include "splay.h"

#include <stdio.h>
#include <stdlib.h>

Knot newKnot(int id)
{
	Knot k;

	k.id = id;
	k.left = NULL;
	k.right = NULL;
	
	return k;
}

void zig(Knot **root)
{
	Knot *k;

	k = (*root)->left;
	(*root)->left = k->right;
	k->right = *root;

	*root = k;
}

void zag(Knot **root)
{
	Knot *k = (*root)->right;

	(*root)->right = k->left;
	k->left = *root;
	*root = k;
}

void zig_zig(Knot **root)
{
	zig(root);
	zig(root);
}

void zag_zag(Knot **root)
{
	zag(root);
	zag(root);
}

void zig_zag(Knot **root)
{
	zig(&(*root)->right);
	zag(root);
}

void zag_zig(Knot **root)
{
	zag(&(*root)->left);
	zig(root);
}

int addKnot(Knot **k, int id)
{
	if(*k == NULL)
	{
		*k = (Knot*)malloc(sizeof(Knot));
		**k = newKnot(id);
	}
	else
		if((*k)->id > id)
			addKnot(&(*k)->left, id);
		else
			if((*k)->id < id)
				addKnot(&(*k)->right, id);
			else
				return FALSE;
	return TRUE;
}

Knot* splay(Knot **root, int id)
{
	int level = 1;
	Knot *k;

	if (*root == NULL)
		return NULL;

	if((*root)->id == id)
		return *root;
 
	if ((*root)->id > id)
	{
		if ((*root)->left == NULL)
			return NULL;

		if ((*root)->left->id > id)
		{
			k = splay(&(*root)->left->left, id);

			if(k != NULL)
			{
				zig(root);
				level = 2;

				printf("Zig-Zig(%d)\n", (*root)->id);
			}
		}
		else if ((*root)->left->id < id)
		{
			k = splay(&(*root)->left->right, id);

			if (k != NULL)
			{
				zag(&(*root)->left);
				level = 2;

				printf("Zig-Zag(%d)\n", (*root)->id);
			}
		}

		if((*root)->left == NULL)
			return NULL;

		if(k!= NULL)
		{
			zig(root);

			if(level == 1)
				printf("zig(%d)\n", (*root)->id);
		}
	}
	else
	{
		if((*root)->right == NULL)
			return NULL;

		if((*root)->right->id > id)
		{
			k = splay(&(*root)->right->left, id);

			if (k != NULL)
			{
				zig(&(*root)->right);
				level = 2;

				printf("zag-zig(%d)\n", (*root)->id);
			}
		}
		else if((*root)->right->id < id)
		{
			k = splay(&(*root)->right->right, id);

			if(k != NULL)
			{
				zag(root);
				level = 2;

				printf("zag-zag(%d)\n", (*root)->id);
			}
		}

		if((*root)->right == NULL)
			return NULL;

		if(k!=NULL)
		{
			zag(root);

			if(level == 1)
				printf("zag(%d)\n", (*root)->id);
		}
	}

	return k;
}

int rmvKnot(Knot **k, int id)
{
	if(*k == NULL)
		return FALSE;
	else
		if((*k)->id > id)
			rmvKnot(&(*k)->left, id);
		else
			if((*k)->id < id)
				rmvKnot(&(*k)->right, id);
			else
				free(*k);
	return TRUE;
}

void mostrar_arvore(Knot *arvore, int nivel)
{
	int n;
	int i;
	int largura = 4;

	if( arvore != NULL )
	{
		mostrar_arvore( arvore->right, nivel+1 );
		printf("\n");

		n = nivel*largura;
		for( i=0; i<n; i++ )
		{
			printf(" ");
		}

		printf("%2d--**", arvore->id);

		mostrar_arvore( arvore->left, nivel+1 );
	}
	
}

void printTree(Knot *root)
{
	printf("\n------------------------------");
	mostrar_arvore(root, 0);
	printf("\n------------------------------\n");
}