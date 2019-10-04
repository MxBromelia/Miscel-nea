#include "foo.h"
#include <iostream>

using namespace std;

int main()
{
	foo::Foo<int> fooo(5,5);
	cout << fooo.foo() << endl;

	foo::Foo<double> bar(5,7.5);
	cout << bar.foo() << endl;

	return 0;
}