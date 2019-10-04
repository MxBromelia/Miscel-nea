#include <iostream>

using namespace std;

int mdc(int a, int b)
{
	return (a%b ? mdc(b, a%b): b);
}

int main()
{
	int i;
	int nums[2], num;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> nums[0] >> nums[1] >> num;

	for(i=0; num > 0; i = (i+1)%2)
		num -= mdc(num, nums[i]);

	cout << ! i << '\n';

	return 0;
}