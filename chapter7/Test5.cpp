//
// Created by ljx on 2022/9/21.
//
#include <iostream>
using namespace std;

long long factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num-1);
}

int main()
{
    int in;
    cout << "input a number:";
    while(cin >> in)
    {
        cout << in << "!=" << factorial(in) << endl;
        cout << "input a number:";
    }
}