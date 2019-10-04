#include <stdio.h>

typedef struct
{
	int h;
	int m;
	int s;
} tempo;

int main()
{
	int segundos;

	tempo t;

	scanf("%d", &segundos);

	t.h = segundos/3600;
	t.m = (segundos % 3600)/60;
	t.s = segundos % 60;

	printf("%d:%d:%d\n", t.h, t.m, t.s);

	return 0;
}