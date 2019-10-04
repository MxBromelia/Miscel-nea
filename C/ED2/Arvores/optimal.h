#ifndef OPTIMAL_H
#define OPTIMAL_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !0

typedef struct
{
	int id;
	int frequency;
} Info;

typedef struct kn
{
	void *content;
	Info info;

	struct kn *left;
	struct kn *right;
} Knot;

Info newInfo(int id, int frequency);
void construct(Knot **root, Info *content, int nContent);
Knot  *search(Knot **root, int id);

void mostrar_arvore(Knot *arvore, int nivel);

int addKnot(Knot **root, Info info);

#endif