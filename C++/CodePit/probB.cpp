#include <iostream>

using namespace std;

int main()
{
	int a,b;

	cin >> a;
	cin >> b;

	if((a%b) && (b%a))
		cout << "Nao sao Multiplos" << endl;
	else
		cout << "Sao Multiplos" << endl;

	return 0;
}