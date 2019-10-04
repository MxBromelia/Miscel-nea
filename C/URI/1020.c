#include <stdio.h>

int main()
{
	int total;

	scanf("%d", &total);

	printf("%d ano(s)\n", total/365);
	printf("%d mes(es)\n", (total % 365)/30);
	printf("%d dia(s)\n", ((total % 365) % 30));

	return 0;
}