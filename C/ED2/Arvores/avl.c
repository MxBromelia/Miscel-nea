#include"avl.h"

Content newContent(int id)
{
	Content c;
	c.id = id;
	return c;
}

Knot newKnot(Content c)
{
	Knot k;

	k.dif = 0;
	k.content = c;
	k.left = NULL;
	k.right = NULL;
	
	return k;
}

void rttLL(Knot **root)
{
	Knot *k;

	printf("simples-direita(%d)\n", (*root)->content.id);

	k = (*root)->left;
	(*root)->left = k->right;
	k->right = *root;
	
	(*root)->dif = (*root)->dif - k->dif - 1;
	k->dif--;
	
	*root = k;
}

void rttRR(Knot **root)
{
	Knot *k;

	printf("simples-esquerda(%d)\n", (*root)->content.id);

	k = (*root)->right;
	(*root)->right = k->left;
	k->left = *root;

	(*root)->dif = (*root)->dif - k->dif + 1;
	k->dif++;
	
	*root = k;
}

void rttLR(Knot **root)
{
	Knot *l;
	Knot *lr;

	printf("dupla-direita(%d)\n", (*root)->content.id);

	l = (*root)->left;
	lr = l->right;

	(*root)->left = lr->right;
	lr->right = *root;
	l->right = lr->left;
	lr->left = l;

	switch(lr->dif)
	{
		case -1:
			(*root)->dif = 0;
			l->dif = 1;
			break;
		case 1:
			(*root)->dif = -1;
			l->dif = 0;
			break;
		default:
			(*root)->dif = 0;
			l->dif = 0;
			break;
	}

	*root = lr;
	(*root)->dif = 0;
}

void rttRL(Knot **root)
{
	Knot *r;
	Knot *rl;

	printf("dupla-esquerda(%d)\n", (*root)->content.id);

	r = (*root)->right;
	rl = r->left;

	(*root)->right = rl->left;
	rl->left = *root;
	r->left = rl->right;
	rl->right = r;

	switch(rl->dif)
	{
		case -1:
			(*root)->dif = 1;
			r->dif = 0;
			break;
		case 1:
			(*root)->dif = 0;
			r->dif = -1;
			break;
		default:
			(*root)->dif = 0;
			r->dif = 0;
			break;
	}

	*root = rl;
	(*root)->dif = 0;
}

void rttLeft(Knot **root) //Inserção à esquerda. Desbalanceamento: (*root)->dif = 2
{
	Knot *k;
	k = (*root)->left;

	if(k->dif == -1)
		rttLR(root);
	else
		rttLL(root);
}

void rttRight(Knot **root) //Inserção à direita. Desbalanceamento: (*root)->dif = -2
{
	Knot *k;

	k = (*root)->right;

	if(k->dif == 1)
		rttRL(root);
	else
		rttRR(root);
}

int addKnot(Knot **root, Content c)
{
	int ok;

	if(*root == NULL)
	{
		*root = malloc(sizeof(Knot));
		**root = newKnot(c);

		return TRUE;
	}
	
	if((*root)->content.id > c.id)
	{
		ok = addKnot(&(*root)->left, c);
		if(ok)
		{
			(*root)->dif++;
			switch((*root)->dif)
			{
				case 0:
					ok = FALSE;
					break;
				case 2:
					rttLeft(root);
					ok = FALSE;
					break;
			}
		}
	}	
	else
		if((*root)->content.id < c.id)
		{
			ok = addKnot(&(*root)->right, c);

			if(ok)
			{
				(*root)->dif--;
				switch((*root)->dif)
				{
					case 0:
						ok = FALSE;
						break;
					case -2:
						rttRight(root);
						ok = FALSE;
						break;
				}
			}
		}
		else
			ok = 0;

	return ok;
}

Knot* srcKnot(Knot *root, Content c)
{
	Knot* pointer;
	
	pointer = root;
	
	do
	{
		if(pointer->content.id == c.id)
			return pointer;
		else
			if(pointer->content.id > c.id)
				pointer = pointer->left;
			else
				pointer = pointer->right;
	}
	while(pointer != NULL);
	
	return NULL;
}

int rmvKnot(Knot **root, Content c)
{
	Knot *k;
	Content content;
	int ok = FALSE;

	if(*root == NULL)
		return FALSE;
	
	if((*root)->content.id == c.id)
	{
		if((*root)->right == NULL)
		{
			if((*root)->left == NULL)
			{
				free(*root);
				*root = NULL;
			}
			else
			{
				k = *root;
				*root = (*root)->left;
				free(k);
			}
		}
		else
		{
			if((*root)->left == NULL)
			{
				k = *root;
				*root = (*root)->right;
				free(k);
			}
			else
			{
				k = (*root)->left;
				
				while(k->right != NULL)
					k = k->right;
				
				content = k->content;
				rmvKnot(root, content);
				(*root)	->content = content;

				if((*root)->dif!=0)
					return FALSE;
			}
		}
		
		return TRUE;
	}
	
	if((*root)->content.id > c.id)
	{
		ok = rmvKnot(&(*root)->left, c);
		
		if(ok)
		{
			(*root)->dif--;
			switch((*root)->dif)
			{
				case -1:
					ok = FALSE;
					break;
				case -2:
					rttRight(root);
					break;
			}
		}
	}
	else
	{
		ok = rmvKnot(&(*root)->right, c);

		if(ok)
		{
			switch((*root)->dif)
			{
				case 1:
					(*root)->dif = 2;
					rttLeft(root);
					break;
				case 0:
					(*root)->dif = 1;
					ok = FALSE;	
					break;
				case -1:
					(*root)->dif = 0;
					break;
			}
		}
	}
	
	return ok;
}

// Imprime a arvore.
void mostrar_arvore( Knot *arvore, int nivel )
{
    int n;
    int i;
    int largura = 5;

    if( arvore != NULL )
    {
        mostrar_arvore( arvore->right, nivel+1 );
        printf("\n");

        n = nivel*largura;
        for( i=0; i<n; i++ )
        {
            printf(" ");
        }

		printf("%2d|%2d", arvore->content.id, arvore->dif);

        mostrar_arvore( arvore->left, nivel+1 );
    }
	
}

void pTree(Knot *k)
{
	printf("----------------------------");
	mostrar_arvore(k, 0);
	printf("\nAltura: %d",height(k));
	printf("\n----------------------------\n");
}

int height(Knot *root)
{
	if(root == NULL)
		return 0;
	if(root->dif > 0)
		return height(root->right) + root->dif + 1;
	return height(root->left) - root->dif + 1;
	//return MAX(height(root->left), height(root->right)) + 1;
}