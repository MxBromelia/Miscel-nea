#include<stdio.h>
#include<stdlib.h>

#define NO_CONTENT_FOUND 0
#define REMOVE_SUCESS 1

typedef struct
{
	int id;
}
Content;

typedef struct kn
{
	Content content;
	
	//struct kn *Father;
	struct kn *left;
	struct kn *right;
	
	int dif;
} Knot;

Content newContent();
//void generateId(Content *c);
Knot newKnot();
int addKnot(Knot *root, Content c);
Knot* srcKnot(Knot *root, Content c);
int rmvKnot(Knot *root, Content c);

int main()
{
	return 0;
}

Content newContent()
{
	Content c;
	c.id = 0;
	return c;
}

Knot newKnot(Content c)
{
	Knot k;
	k.content = c;
	
	return k;
}

int addKnot(Knot *root, Content c)
{
	Knot *k;
	Knot *pointer;
	
	k = malloc(sizeof(Knot));
	*k = newKnot(c);
	
	pointer = root;
	
	while(1)
	{
		if(pointer->c.id > c.id)
		{
			if(kn->left != NULL)
				kn = kn->left;
			else
				break;
		}
		else
		{
			if(kn->right != NULL)
				kn = kn->right;
			else
				break;
		}
	}
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

int rmvKnot(Knot *root, Content c)
{
	Knot *k;
	k = srcKnot(root, c);
	
	if(k == NULL)
		return NO_CONTENT_FOUND;
	
	if(k->left == NULL && k->right == NULL)
		free(k);
	
	return REMOVE_SUCESS;
}
