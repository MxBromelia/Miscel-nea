#include <stdio.h>
#include <stdlib.h>

void mount_random_file(int city_num, int dist_max)
{
	int i, j;
	FILE* dist = fopen("dist.txt", "w");

	fprintf(dist, "%d\n", city_num);

	for(i=0; i<city_num; i++)
		for(j=0;j<city_num; j++)
			fprintf(dist, "%d%c", (i!= j? rand() % dist_max : 0), (j<city_num-1 ? ' ' : '\n'));
	fclose(dist);
}

int main(int argc, char** argv)
{
	switch(argc)
	{
			case 2:
				mount_random_file( atoi(argv[1]), 10);
				break;
			case 3:
				mount_random_file( atoi(argv[1]), atoi(argv[2]));
				break;
			default:
				fprintf(stderr, "Deu ruim!\n");
	}

	return 0;
}