//
// Created by ljx on 2022/9/16.
//

#include<iostream>
using namespace std;

int main()
{
    double hkm2mile = 62.14, gallon2l = 3.785, input;
    cout << "Input the fuel consumption per 100km: ";
    cin >> input;
    double gallon = input / gallon2l, mile = hkm2mile;
    cout << input << "L/100km = " << mile / gallon << "mpg" << endl;
}