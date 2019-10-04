#include <stdio.h>

int main()
{
	int cases;
	int seq[3];

	int i;

	scanf("%d", &cases);

	for(i=1;i<=cases;i++)
	{
		seq[0] = i;
		seq[1] = seq[0]*seq[0];
		seq[2] = seq[0]*seq[1];

		printf("%d %d %d\n", seq[0], seq[1], seq[2]);

		seq[1]++;
		seq[2]++;

		printf("%d %d %d\n", seq[0], seq[1], seq[2]);
	}

	return 0;
}