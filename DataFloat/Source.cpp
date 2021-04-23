#include<iostream>
#include<fstream>
#include <cstdlib>
using namespace std;

int main()
{
	ofstream output;
	output.open("output.txt", ios::out);
	static float a[1000000];
	srand(time(nullptr));
	for (int i = 999999; i >= 0; i--)
	{
		//a[i]=(rand() / (RAND_MAX / (2000.0+1)))-1000.0;
		output<<i+0.5<<endl;
	}

	return 1;

}