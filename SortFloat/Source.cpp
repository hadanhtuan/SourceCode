#include<iostream>
#include<algorithm>
#include<fstream>
#include <time.h>

using namespace std;
bool SoSanh(const float a, const float b)
{
	return a < b;
}

int main()
{
	ifstream input;
	ofstream output;
	clock_t start, end;
	double time_use;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	static float a[1000000];
	for (int i = 0; i < 1000000; i++)
	{
		input >> a[i];				// doc du lieu tu input
	}
	start = clock();
	sort(a, a + 999999, SoSanh);
	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use;

	for (int i = 0; i < 1000000; i++)
		output << a[i] << endl;			// ghi du lieu da duoc sap xep vao output

	input.close();
	output.close();
	return 0;
}