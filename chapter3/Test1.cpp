//
// Created by ljx on 2022/9/8.
//
#include<iostream>
using namespace std;

int main()
{
    const double inch2foot = 12;
    double height, res;
    wcout << L"Input your height:";
    cin >> height;
    res = height / inch2foot;
    cout << "your height is " << res << " foot." << endl;
}