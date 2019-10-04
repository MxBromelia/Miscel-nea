#ifndef SPLAY_H
#define SPLAY_H

#define TRUE !0
#define FALSE 0

typedef struct kn
{
	int id;

	struct kn* left;
	struct kn* right;
}
Knot;

Knot newKnot(int id);

int addKnot(Knot **k, int id);
int rmvKnot(Knot **k, int id);
Knot* splay(Knot **root, int id);

void printTree(Knot* root);

#endif