#include<iostream>
#include<algorithm>
#include<fstream>
#include <time.h>

using namespace std;
void quickSort(int[], int, int);


int main()
{
	ifstream input;
	ofstream output;
	clock_t start, end;
	double time_use;
	input.open("input.txt", ios::in);
	output.open("output.txt", ios::out);
	static int a[1000000];
	for (int i = 0; i < 1000000; i++)
	{
		input >> a[i];			// doc du lieu tu input
	}
	start = clock();
	quickSort(a, 0, 999999);
	end = clock();

	time_use = (double)(end - start) / CLOCKS_PER_SEC;

	cout << time_use;

	for (int i = 0; i < 1000000; i++)
		output << a[i] << endl;			// ghi du lieu da duoc sap xep vao output

	input.close();
	output.close();
	return 0;
}

void quickSort(int Data[], int l, int r)
{
	if (l <= r)
	{
		float key = Data[(l + r) / 2];

		int i = l;
		int j = r;

		while (i <= j)
		{
			while (Data[i] < key)
				i++;
			while (Data[j] > key)
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}


		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}