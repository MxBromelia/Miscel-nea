#include <iostream>

using namespace std;

int r(int x, int y)
{
	return (3*x)*(3*x) + y*y;
}

int b(int x, int y)
{
	return 2*(x*x) + (5*y)*(5*y);
}

int c(int x, int y)
{
	return -100*x + y*y*y;
}

int main()
{
	int N;
	int x, y;
	int result[3];
	int maior;

	char nome[3][8] = {"Rafael", "Beto", "Carlos"};

	cin >> N;

	while(N>0)
	{
		cin >> x;
		cin >> y;

		result[0] = r(x,y);
		result[1] = b(x,y);
		result[2] = c(x,y);

		maior = 0;

		if(result[1] > result[0])
			maior = 1;

		if(result[2] > result[maior])
			maior = 2;

		cout << nome[maior] << " Ganhou" << endl;

		N--;
	}

	return 0;
}