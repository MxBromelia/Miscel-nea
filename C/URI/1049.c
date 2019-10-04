#include <stdio.h>
#include <string.h>

typedef	char* string;

int main()
{
	const string animais[] = {"aguia", "pomba", "homem", "vaca", "pulga", "lagarta", "sanguessuga", "minhoca"};
	char caracter[3][20];

	int animal = 0;

	scanf("%s", caracter[0]);
	scanf("%s", caracter[1]);
	scanf("%s", caracter[2]);

	if(! strcmp(caracter[0], "invertebrado"))
	{
		animal = animal | 4;
		if(! strcmp(caracter[1], "anelideo"))
		{
			animal = animal | 2;
			if(!strcmp(caracter[2], "onivoro"))
				animal = animal | 1;
		}
		else
			if(! strcmp(caracter[2], "herbivoro"))
				animal = animal | 1;
	}
	else
	{
		if(! strcmp(caracter[1], "mamifero"))
		{
			animal = animal | 2;
			if(! strcmp(caracter[2], "herbivoro"))
				animal = animal | 1;
		}
		else
		{
			if(! strcmp(caracter[2], "onivoro"))
				animal = animal | 1;
		}
	}

	printf("%s\n", animais[animal]);

	return 0;
}