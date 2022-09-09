//
// Created by ljx on 2022/9/9.
//

#include<iostream>
using namespace std;

int main()
{
    const short exp = 60;
    int degree;
    short minutes, seconds;
    double res;
    cout << "Enter the degree:";
    cin >> degree;
    cout << "Enter the minutes(<60):";
    cin >> minutes;
    cout << "Enter the seconds(<60):";
    cin >> seconds;
    res = degree + float(minutes) / 60.f + float (seconds) / 3600.f;
    cout << degree << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << res << " degrees." << endl;
}