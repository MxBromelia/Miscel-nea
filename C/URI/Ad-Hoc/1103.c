#include <stdio.h>

typedef struct
{
	int h;
	int m;
} Horario;

int main()
{
	Horario a, b;

	scanf("%d %d %d %d", &a.h, &a.m, &b.h, &b.m);

	while(a.h != 0 || a.m != 0 || b.h != 0 || b.m != 0)
	{
		printf("%d\n", ((b.h - a.h)*60 + (b.m - a.m) + 1440)% 1440);
		scanf("%d %d %d %d", &a.h, &a.m, &b.h, &b.m);
	}

	return 0;
}