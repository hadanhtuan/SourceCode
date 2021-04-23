#include<iostream>
#include<algorithm>
#include<fstream>
#include <time.h>

using namespace std;
void heapify(int[], int, int);
void heapSort(int[], int);


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
        input >> a[i];  // doc du lieu tu input
    }
    start = clock();
    heapSort(a, 1000000);
    end = clock();

    time_use = (double)(end - start) / CLOCKS_PER_SEC;

    cout << time_use;

    for (int i = 0; i < 1000000; i++)
        output << a[i] << endl;     // ghi du lieu da duoc sap xep vao output

    input.close();
    output.close();
    return 0;
}
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}