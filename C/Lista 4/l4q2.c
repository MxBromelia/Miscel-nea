#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char* string;

typedef struct
{
	char nome[50];
	int idade;
} Cliente;

typedef struct cel
{
	Cliente this;
	struct cel *next;
} Celula;

Cliente newCliente(string nome, int idade);
void addToList(Celula *head, Cliente c, int index);
void rmvFromList(Celula *head, int index);
Celula* acsInList(Celula *head, int index);
void swapListEl(Celula *head, int id1, int id2);
void listInvList(Celula *head);
Celula* splitLista(Celula *head, Cliente c);
void invList(Celula *head);

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

void addToList(Celula *head, Cliente c, int index)
{
	int i;

	Celula *cel, *p;

	cel = malloc(sizeof(Celula));
	cel->this = c;
	cel->next = NULL;

	p = head;
	if(p->next!=NULL)
	{
		for(i=0;i<index;i++)
		{
			p = p->next;

			if(p->next == NULL)
				break;
		}

		cel->next = p->next;
	}
	
	p->next = cel;
}

void rmvFromList(Celula *head, int index)
{
	int i;

	Celula *p, *q;

	p = head;

	if(p->next!=NULL)
	{
		for(i=0;i<index; i++)
		{
			p = p->next;

			if(p->next==NULL)
				break;
		}

		if(p->next!=NULL)
		{
			q = p->next;

			p->next = q->next;

			free(q);
		}
		else
			printf("A lista nao contem nenhum elemento neste indice!\n");
	}
	else
		printf("Lista Vazia!\n");
}

Celula* acsInList(Celula *head, int index)
{
	int i =-1;

	Celula *p;

	p = head;

	if(p->next!=NULL)
		for(i=0, p = p->next;i< index && p->next!=NULL; i++)
			p = p->next;

	if(i<index)
		p = NULL;

	return p;
}

void swapListEl(Celula *head, int id1, int id2)
{
	Cliente swap;
	Celula *c1;
	Celula *c2;

	c1 = malloc(sizeof(Cliente));
	c2 = malloc(sizeof(Cliente));

	c1 = acsInList(head, id1);

	if(c1!=NULL)
	{
		c2 = acsInList(head, id2);

		if(c2!=NULL)
		{
			swap = c1->this;
			c1->this = c2->this;;
			c2->this = swap;
		}
		else
			printf("Erro!\n");
	}
	else
		printf("Erro!\n");
}

void listInvListNoHead(Celula *c)
{
	if(c->next!=NULL)
		listInvListNoHead(c->next);
	printf("Nome: %s| Idade: %d\n", c->this.nome, c->this.idade);
}

void listInvList(Celula *head)
{
	listInvListNoHead(head->next);
}

int cmpCliente(Cliente c1, Cliente c2)
{
	if(c1.idade == c2.idade)
		if(!strcmp(c1.nome, c2.nome))
			return !0;
	return 0;
}

Celula* splitLista(Celula *head, Cliente c)
{
	Celula *h2, *p;

	h2 = malloc(sizeof(Celula));

	p = head;

	while(p->next!=NULL)
	{
		if(cmpCliente(c, p->next->this))
			break;
		p = p->next;
	}

	h2->next = p->next;
	p->next = NULL;

	return h2;
}

void invList(Celula *head)
{
	int i;
	int lSize;

	Celula *p;
	
	if(head->next!=NULL)
		for(lSize=0, p = head->next; p!=NULL; lSize++)
			p = p->next;

	for(i=0;i<lSize/2;i++)
		swapListEl(head, i, lSize-i-1);
}
