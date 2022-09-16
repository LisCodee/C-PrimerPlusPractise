//
// Created by ljx on 2022/9/16.
//

#include<iostream>
using namespace std;

int main()
{
    long distance, gas;
    cout << "Enter the distance(Mile):";
    cin >> distance;
    cout << "Enter the gas consumed:";
    cin >> gas;
    double res = double(distance) / double(gas);
    cout << "Fuel consumption: " << res << " Mile/Gallon";
}