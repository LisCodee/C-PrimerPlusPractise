//
// Created by ljx on 2022/9/21.
//
#include <iostream>
using namespace std;

int getInput(double* arr, int size)
{
    int length;
    cout << "Input golf score(most ten records, end with -1):";
    double in;
    cin >> in;
    for (int i = 0; cin.good() && in != -1 && i < size; ++i) {
        ++length;
        arr[i] = in;
        cin >> in;
    }
    return length;
}

void showScore(double* arr, int length)
{
    cout << "Score:" << endl;
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

double getAverage(double* arr, int length)
{
    double sum;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum/length;
}
int main()
{
    double* arr = new double[10];
    int len = getInput(arr, 10);
    showScore(arr, len);
    double ave = getAverage(arr, len);
    cout << "average is: " << ave << endl;
}