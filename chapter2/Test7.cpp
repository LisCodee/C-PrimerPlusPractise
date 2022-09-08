//
// Created by ljx on 2022/9/8.
//

#include<iostream>
using namespace std;

void showTime(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes <<endl;
}
int main()
{
    int hours, minutes;
    cout << "Enter the number of hours:";
    cin >> hours;
    cout << "Enter the number of minutes:";
    cin >> minutes;
    showTime(hours, minutes);
}