#include <stdio.h>

typedef char* string;

int main()
{
	int i;
	string meses[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	scanf("%d", &i);

	printf("%s\n", meses[i]);

	return 0;
}