//
// Created by ljx on 2022/9/17.
//
#include<iostream>

using namespace std;

int main()
{
    int daphne, cleo, flag = 0, daphneInterest = 0;
    daphne = cleo = 100;
    while (cleo <= (daphne + daphneInterest))
    {
        ++flag;
        daphneInterest += daphne * 0.1;
        cleo *= 1.05;
    }
    cout << "After " << flag << " years, Cleo is richer than daphne" << endl;
    cout << "daphne: $" << daphne + daphneInterest << endl;
    cout << "Cleo: $" << cleo << endl;
}