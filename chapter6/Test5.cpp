//
// Created by ljx on 2022/9/20.
//
#include<iostream>

using namespace std;

int main()
{
    double in, tax;
    cin >> in;
    while(cin.good())
    {
        if(in < 0)
            exit(0);
        if (in <= 5000)
            tax = 0;
        else if(in > 5000 && in <= 15000)
            tax = (in - 5000) * 0.1;
        else if(in > 15000 && in <= 35000)
            tax = 10000 * 0.1 + (in - 35000) * 0.15;
        else if(in > 35000)
            tax = 10000 * 0.1 + 20000 * 0.15 + (in - 35000) * 0.2;
        cout << "tax: " << tax << endl;
        cin >> in;
    }
}