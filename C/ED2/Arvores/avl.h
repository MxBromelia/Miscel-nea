#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#define ABS(A) ((A>0) ? (A):(-A))

#define TRUE !0
#define FALSE 0

#define VOID_TREE 0
#define NON_VOID_TREE 1

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

Content newContent(int id);
Knot newKnot(Content c);
int addKnot(Knot **root, Content c);
Knot* srcKnot(Knot *root, Content c);
int rmvKnot(Knot **root, Content c);
void mostrar_arvore(Knot *arvore, int nivel);
int height(Knot *root);

#endif