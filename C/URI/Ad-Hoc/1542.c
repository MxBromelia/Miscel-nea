#include <stdio.h>

int main()
{
	int Q, D, P;

	int pgs;

	scanf("%d", &Q);

	while(Q != 0)
	{
		scanf("%d %d", &D, &P);

		pgs = Q*P*D/(P-Q);

		if(pgs != 1)
			printf("%d paginas\n", pgs);
		else
			printf("%d pagina\n", pgs);

		scanf("%d", &Q);
	}

	return 0;
}