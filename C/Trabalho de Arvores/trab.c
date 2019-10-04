#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE !0
#define FALSE 0

#define PRINT 1
#define PREDEFTRANS 2
#define TRANSLATE 3
#define SHUTDOWN 4

typedef int boolean;
typedef char* string;

typedef struct
{
	char decoded;
	char coded;
} Cesar;

typedef struct kn
{
	Cesar content;
	//struct kn *up;
	struct kn *left;
	struct kn *right;
} Knot;

//Códigos Relacionados à Árvore
Cesar newCesar(char decoded);
Knot newKnot(Cesar c);
void addKnot(Knot *root, Cesar c);
void crtLetterTree(Knot *root);
Knot* srcKnotDecoded(Knot *root, char decoded);
Knot* srcKnotCoded(Knot *root, char coded);
char anotherStatus(Knot *root, char c, boolean *decoded);
string translate(string message, boolean decoded);
void listTreePreOrd(Knot *root);
void listTreeOrd(Knot *root);
void listTreePosOrd(Knot *root);
void preDefTrans();

//Códigos Relacionádos à Interface de Usuário
void menu();

int main()
{
	/*Knot *root = malloc(sizeof(Knot));
	
	crtLetterTree(root);*/
	menu();
	
	/*listTreePreOrd(root);
	printf("\n");
	listTreeOrd(root);
	printf("\n");
	listTreePosOrd(root);*/
	
	return 0;
}

//Codigos Relacionados à Árvore
Cesar newCesar(char decoded)
{
	Cesar c;
	
	c.decoded = decoded;
	
	if(decoded>='a' && decoded<='z')
		decoded-=32;
	
	if(decoded>='A' && decoded<'D')
		decoded+=26;
	
	decoded -= 3;
	
	c.coded = decoded;
	
	return c;
}

Knot newKnot(Cesar c)
{
	Knot k;
	
	k.content = c;
	k.left = NULL;
	k.right = NULL;
	
	return k;
}

Knot* srcKnotDecoded(Knot *root, char decoded)
{
	Knot *k;
	
	k = root;
	
	if(decoded>='a' && decoded<='z')
		decoded -= 32;
	
	while(k!=NULL)
	{
		if(k->content.decoded < decoded)
			k = k->right;
		else
			if(k->content.decoded > decoded)
				k = k->left;
			else
				break;
	}
	
	if(k == NULL)
	{
		k = malloc(sizeof(Knot));
		k->content.decoded = decoded;
		k->content.coded = decoded;
	}
	
	return k;
}

Knot* srcKnotCoded(Knot *root, char coded)
{
	Knot *k;
	
	k = root;
	
	if(coded>='a' && coded<='z')
		coded -= 32;
	
	while(k!=NULL)
	{
		if(k->content.coded < coded)
			k = k->right;
		else
			if(k->content.coded > coded)
				k = k->left;
			else
				break;
	}
	
	if(k == NULL)
	{
		k = malloc(sizeof(Knot));
		k->content.decoded = coded;
		k->content.coded = coded;
	}
	
	return k;
}

char anotherStatus(Knot *root, char c, boolean *decoded)
{
	char ret;
	Knot* k;
	
	if(*decoded)
	{
		k = srcKnotDecoded(root, c);
		
		ret = k->content.coded;
	}
	else
	{
		k = srcKnotCoded(root, c);
		
		ret = k->content.decoded;
	}
	
	*decoded = ! *decoded;
	
	return ret;
}

string translate(string message, boolean decoded)
{
	int i;
	int strLen = strlen(message);
	char *ret;
	
	Knot *root;
	root = malloc(sizeof(Knot));
	crtLetterTree(root);
	
	ret = malloc(sizeof(char)*(strLen+1));
	
	for(i=0;message[i] != '\0';i++)
	{
		ret[i] = anotherStatus(root, message[i], &decoded);
		decoded = !decoded;
	}
	
	return ret;
}

void addKnot(Knot *root, Cesar c)
{
	Knot *k, *kn;
	
	k = malloc(sizeof(Knot));
	
	k->content = c;
	k->left = NULL;
	k->right = NULL;
	
	kn = root;
	
	while(1)
	{
		if(c.decoded <= kn->content.decoded)
		{
			if(kn->left != NULL)
			{
				kn = kn->left;
			}
			else
				break;
		}
		else
		{
			if(kn->right !=NULL)
			{
				kn = kn->right;
			}
			else
				break;
		}
	}
	
	if(c.decoded <= kn->content.decoded)
		kn->left = k;
	else
		kn->right = k;
}

void crtLetterTree(Knot *root)
{
	root->content = newCesar('P');
	
	addKnot(root, newCesar('H'));
	addKnot(root, newCesar('X'));
	
	addKnot(root, newCesar('D'));
	addKnot(root, newCesar('L'));
	addKnot(root, newCesar('T'));
	addKnot(root, newCesar('Z'));
	
	addKnot(root, newCesar('B'));
	addKnot(root, newCesar('F'));
	addKnot(root, newCesar('J'));
	addKnot(root, newCesar('N'));
	addKnot(root, newCesar('R'));
	addKnot(root, newCesar('V'));
	addKnot(root, newCesar('Y'));
	
	addKnot(root, newCesar('A'));
	addKnot(root, newCesar('C'));
	addKnot(root, newCesar('E'));
	addKnot(root, newCesar('G'));
	addKnot(root, newCesar('I'));
	addKnot(root, newCesar('K'));
	addKnot(root, newCesar('M'));
	addKnot(root, newCesar('O'));
	addKnot(root, newCesar('Q'));
	addKnot(root, newCesar('S'));
	addKnot(root, newCesar('U'));
	addKnot(root, newCesar('W'));
	
	srcKnotDecoded(root, 'Z')->right = srcKnotDecoded(root, 'B');
}

void listTreePreOrd(Knot *root)
{
	printf("%c\t%c\n", root->content.decoded, root->content.coded);
	if(root->left!=NULL)
		listTreePreOrd(root->left);
	if(root->right!=NULL)
		listTreePreOrd(root->right);
}

void listTreeOrd(Knot *root)
{
	if(root->left!=NULL)
		listTreeOrd(root->left);
	printf("%c\t%c\n", root->content.decoded, root->content.coded);
	if(root->right!=NULL)
		listTreeOrd(root->right);
}

void listTreePosOrd(Knot *root)
{
	if(root->left!=NULL)
		listTreePosOrd(root->left);
	if(root->right!=NULL)
		listTreePosOrd(root->right);
	printf("%c\t%c\n", root->content.decoded, root->content.coded);
}

void preDefTrans()
{
	printf("%s\n", translate("ESSE E O TRABALHO DE ARVORES DA DISCIPLINA DE ED1",TRUE));
	printf("%s\n", translate("O TRABALHO FOI ENTREGUE ANTES DO DIA 19 DE FEVEREIRO",TRUE));
	printf("%s\n", translate("AGUARDANDO O RESULTADO DO TRABALHO",TRUE));
	printf("%s\n", translate("Ylx ploqb",FALSE));
	printf("%s\n", translate("Bsfixpfl",FALSE));
}

//Códigos Relacionados à Interface de Usuário
void menu()
{
	int opt = 0;
	boolean state;
	string msg = malloc(sizeof(char)*100);
	Knot *root;
	
	root = malloc(sizeof(Knot));
	
	crtLetterTree(root);
	
	do
	{
		printf("Menu:\n");
		printf("1 - Imprimir Árvore em Ordem\n");
		printf("2 - Traduzir Valores Pré-Definidos\n");
		printf("3 - Traduzir um Frase Digitada pelo Usuário\n");
		printf("4 - Sair\n");
		printf("->");
		
		scanf("%d", &opt);
		
		switch(opt)
		{
			case PRINT:
				listTreeOrd(root);
				break;
			case PREDEFTRANS:
				preDefTrans();
				break;
			case TRANSLATE:
				printf("Digite a frase a ser traduzida:\n");
				//scanf("%[^\n]s", msg);
				scanf("%s", msg);
				printf("\n");
				printf("Digite 0 se a mensagem estiver codificada. Se não, 1.\n");
				scanf("%d", &state);
				printf("%s\n", translate(msg, state));
				break;
			case SHUTDOWN:
				break;
			default:
				printf("Comando Inválido!\n");
				opt = 0;
				break;
		}
	}
	while(opt!=SHUTDOWN);
}
