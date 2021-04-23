#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;

int main()
{
	ofstream output; 
	output.open("output.txt", ios::out);
	static int a[1000000];
	srand(time(nullptr));
	for (int i = 0; i <1000000; i++)
	{
		a[i] = rand() % (1000+1000+1) - 1000;   //rand() % (max – min + 1) + min|| [-1000;1000]
		output <<a[i]<<endl;
	}
	output.close();
	return 1;
	
}