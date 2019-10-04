#include <stdio.h>
#include <stdlib.h>

typedef char* string;

int main()
{
	int it;
	int fb;

	int i;

	int* type;
	string resps[] = {"Rolien", "Naej", "Elehcim", "Odranoei"};

	scanf("%d", &it);

	while(it > 0)
	{
		scanf("%d", &fb);

		type = (int*)malloc(sizeof(int)*fb);

		for(i=0;i<fb;i++)
			scanf("%d", &type[i]);

		for(i=0;i<fb;i++)
			printf("%s\n", resps[type[i-1]]);

		free(type);

		it--;
	}

	return 0;
}