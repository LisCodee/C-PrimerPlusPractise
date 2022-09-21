//
// Created by ljx on 2022/9/21.
//
#include <iostream>
using namespace std;

int Fill_array(double* arr, int size)
{
    cout << "Input numbers:";
    int len;
    double in;
    for (int i = 0; i < size && cin >> in; ++i)
    {
        arr[i] = in;
        ++len;
    }
    return len;
}

void Show_array(double* arr, int len)
{
    cout << "Show array:" << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void Reverse_array(double* arr, int len)
{
    double temp;
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    double* arr = new double[10];
    int len = Fill_array(arr, 10);
    Show_array(arr, len);
    Reverse_array(arr, len);
    Show_array(arr, len);
    Reverse_array(arr+1, len-2);
    Show_array(arr, len);
}