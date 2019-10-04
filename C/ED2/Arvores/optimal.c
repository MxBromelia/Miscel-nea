#include "optimal.h"

Info newInfo(int id, int frequency)
{
	Info f;

	f.id = id;
	f.frequency = frequency;

	return f;
}

Knot newKnot(Info info)
{
	Knot k;

	k.info = info;
	k.left = NULL;
	k.right = NULL;

	return k;
}

void pullLeft(Knot **root)
{
	Knot *k;

	k = (*root)->left;
	(*root)->left = k->right;
	k->right = *root;

	*root = k;
}

void pullRight(Knot **root)
{
	Knot *k = (*root)->right;

	(*root)->right = k->left;
	k->left = *root;
	*root = k;
}

int addKnot(Knot **root, Info info)
{
	if(*root == NULL)
	{
		*root = (Knot*)malloc(sizeof(Knot));
		**root = newKnot(info);
	}
	else
		if(info.id < (*root)->info.id)
		{
			addKnot(&(*root)->left, info);

			if((*root)->info.frequency < (*root)->left->info.frequency)
				pullLeft(root);
		}
		else
			if(info.id > (*root)->info.id)
			{
				addKnot(&(*root)->right, info);

				if((*root)->info.frequency < (*root)->right->info.frequency)
					pullRight(root);
			}
			else
				return FALSE;
	return TRUE;
}

void construct(Knot **root, Info *content, int nContent)
{
	while(nContent > 0)
		addKnot(root, content[--nContent]);
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

		printf("%2d|%2d**", arvore->info.id, arvore->info.frequency);

        mostrar_arvore( arvore->left, nivel+1 );
    }
	
}