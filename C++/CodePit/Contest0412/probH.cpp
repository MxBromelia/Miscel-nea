#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int banana;
	int num;
	int emprestimo;
	long long int grana;

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> banana >> grana >> num;

	emprestimo = (banana*(num+1)*num >>1) - grana;
	cout <<  emprestimo*(emprestimo>0) << '\n';

	return 0;
}