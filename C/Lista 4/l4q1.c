#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define END -1

typedef char* string;

typedef struct
{
	char nome[50];
	int idade;
} Cliente;

typedef struct ls
{
	Cliente cliente[100];
	int tamanho;
} Lista;

Cliente newCliente(string nome, int idade);
int cmpCliente(Cliente c1, Cliente c2);
void initLista(Lista *l);
Cliente* acsElemento(Lista *l, int index);
int qtdElemento(Lista *l , Cliente c);
int srcElemento(Lista *l, Cliente c);
void addElemento(Lista *l, Cliente c,unsigned int index);
void rmvElemento(Lista *l, int index);

int main()
{
	return 0;
}

Cliente newCliente(string nome, int idade)
{
	Cliente c;

	strcpy(c.nome, nome);
	c.idade = idade;

	return c;
}

int cmpCliente(Cliente c1, Cliente c2)
{
	if(c1.idade == c2.idade)
		if(! strcmp(c1.nome, c2.nome))
			return !0;
	return 0;
}

void initLista(Lista *l)
{
	l->tamanho = 0;
}

Cliente *acsElemento(Lista *l, int index)
{
	Cliente *c;

	c = malloc(sizeof(Cliente));
	
	if(index< l->tamanho)
		*c = l->cliente[index];
	else
		c = NULL;

	return c;
}

int qtdElemento(Lista *l , Cliente c)
{
	int i, qtd = 0;

	Cliente *cl;

	for(i=0;i< l->tamanho; i++)
	{
		cl = acsElemento(l, i);
		
		if(cmpCliente(c, *cl))
			qtd++;
	}

	return qtd;
}

int srcElemento(Lista *l, Cliente c)
{
	int i;
	Cliente *cl;

	cl = malloc(sizeof(Cliente));

	for(i=0;i < l->tamanho; i++)
	{
		cl = acsElemento(l, i);

		if(cmpCliente(c, *cl))
			return i;
	}

	return -1;
}
	

void addElemento(Lista *l, Cliente c,unsigned int index)
{
	int i;

	for(i=l->tamanho; i>index; i--)
		l->cliente[i] = l->cliente[i-1];

	l->cliente[i] = c;
	l->tamanho++;
}

void rmvElemento(Lista *l, int index)
{
	int i;

	for(i=index;i<l->tamanho-1;i++)
	{
		l->cliente[i] = l->cliente[i+1];
	}

	l->tamanho--;
}
