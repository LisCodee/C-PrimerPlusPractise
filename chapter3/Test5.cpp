//
// Created by ljx on 2022/9/16.
//

#include<iostream>
using namespace std;

int main()
{
    long long worldPopulation, USPopulation;
    cout << "Enter the world's population:";
    cin >> worldPopulation;
    cout << "Enter the population of the US:";
    cin >> USPopulation;
    double res = double(USPopulation) / double(worldPopulation);
    res *= 100;
    cout << "The population of the US is " << res << "% of the world population";

}