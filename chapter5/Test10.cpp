//
// Created by ljx on 2022/9/17.
//
#include<iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter number of rows:";
    cin >> rows;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows; ++j) {
            if((rows - j) >= i)
                cout << ".";
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}