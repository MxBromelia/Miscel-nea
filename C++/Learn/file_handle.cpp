#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream file;
	file.open("wololo.txt",ios::trunc);

	file << "Wololo!" << endl;
	file << "Olha a tapioca!" << endl;

	file.close();
	return 0;
}