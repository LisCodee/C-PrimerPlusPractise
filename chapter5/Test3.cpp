//
// Created by ljx on 2022/9/17.
//
#include<iostream>

using namespace std;

int main()
{
    double sum = 0, input = 0;
    do {
        cout << "Input a number:";
        cin >> input;
        sum += input;
        cout << "current sum is " << sum << endl;
    } while (input);
    return 0;
}