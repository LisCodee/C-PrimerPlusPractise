//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<array>

using namespace std;
const int Size = 101;
int main()
{
    array<long double, Size> arr;
    arr[0] = arr[1] = 1;
    for(int i = 2; i < Size; ++i)
    {
        arr[i] = i * arr[i-1];
    }
    for (int i = 0; i < Size; ++i) {
        cout << i << "! = " << arr[i] << endl;
    }
}