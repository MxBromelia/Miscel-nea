#include<stdio.h>
#include<string.h>

int main()
{
	char* str = "x+2 = y+3 = z";
	char* ptr = str;

	while((ptr = strchr(ptr+1, '=')) != NULL)
		printf("%s\n", ptr);

	return 0;
}