#include <stdio.h>

#define MAX 20

int main()
{
	int num;
	int linCol;

	int i, j;

	int original[MAX][MAX], quadrado[MAX][MAX];

	scanf("%d", &num);

	while(num>0)
	{
		scanf("%d", &linCol);

		for(i=0;i<linCol;i++)
			for(j=0;j<linCol;j++)
				scanf("%d", &original[i][j]);

		for(i=0;i<linCol;i++)
			for(j=0, quadrado[i][j] = 0;j<linCol;j++)
				for(k=0;k<linCol;k++)
					quadrado[i][j] = quadrado[i][j] + original[i][k]*original[k][j];

		printf("");
	}

	return 0;
}