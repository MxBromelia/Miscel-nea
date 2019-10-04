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
	struct cel *prev;
} Celula;

Cliente newCliente(string nome, int idade);
void addToList(Celula *head, Cliente c, int index);
void rmvFromList(Celula *head, int index);
Celula* acsInList(Celula *head, int index);
int distFromBegin(Celula *head, Cliente c);
int distFromEnd(Celula *head, Cliente c);
void listList(Celula *head, int sentido);

int main()
{
	Celula *head;

	head = malloc(sizeof(Celula));

	addToList(head, newCliente("Marcos", 25), 0);
	addToList(head, newCliente("Marcio", 18), 0);
	addToList(head, newCliente("Carlos", 18), 0);
	addToList(head, newCliente("Cassio", 30), 0);
	addToList(head, newCliente("Samuel", 30), 0);

	printf("%d ", distFromBegin(head, newCliente("Samuel", 30)));
	printf("%d\n", distFromEnd(head, newCliente("Samuel", 30)));

	printf("%s %s\n", acsInList(head, 0)->this.nome, acsInList(head, 2)->this.nome);

	rmvFromList(head, 2);

	printf("%s %s\n", acsInList(head, 0)->this.nome, acsInList(head, 1)->this.nome);
	
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

	Celula *p;
	Celula *cel;

	cel = malloc(sizeof(Celula));

	cel->this = c;
	cel->prev = NULL;
	cel->next = NULL;

	p = head;

	if(p->next!=NULL)
	{
		for(i=0;i<index && p->next!=NULL; i++)
			p = p->next;

		cel->prev = p;
		if(p->next!=NULL)
			p->next->prev = cel;
		else
			head->prev = cel;

		cel->next = p->next;
		p->next = cel;
	}
	else
	{
		head->next = cel;
		head->prev = cel;
		cel->prev = head;
	}
}

void rmvFromList(Celula *head, int index)
{
	int i;

	Celula *p;
	Celula *q;

	p = head;

	if(head->next!=NULL)
	{
		for(i=0;i<index && p->next!=NULL; i++)
			p = p->next;

		if(p->next!=NULL)
		{
			q = p->next;
			p->next = q->next;

			if(q->next!=NULL)
			{
				q->next->prev = q;

				free(q);
			}
			else
				head->prev = p;
		}
		else
			printf("O elemento a ser excluído nao existe!");
	}
	else
		printf("A lista esta vazia!");
}

Celula* acsInList(Celula *head, int index)
{
	int i=-1;

	Celula *p;

	p = head;

	if(p->next!=NULL)
		for(i=0, p = head->next; i<index && p->next!=NULL; i++)
			p = p->next;

	if(i<index)
		p = NULL;

	return p;
}

int distFromBegin(Celula *head, Cliente c)
{
	int i;

	Celula *p;

	for(i=0, p=head->next; p!=NULL; i++, p = p->next)
		if(p->this.idade == c.idade)
			if(strcmp(p->this.nome, c.nome))
				return i;

	return -1;
}

int distFromEnd(Celula *head, Cliente c)
{
	int i;

	Celula *p;

	for(i=0,p=head->prev; p!=NULL; i++, p = p->prev)
		if(p->this.idade == c.idade)
			if(strcmp(p->this.nome, c.nome))
				return i;

	return -1;
}
