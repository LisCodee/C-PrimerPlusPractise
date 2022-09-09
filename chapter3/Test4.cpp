//
// Created by ljx on 2022/9/9.
//

#include<iostream>
using namespace std;

int main()
{
    long second;
    const short hours = 24, minutes = 60, seconds = 60;
    cout << "Enter the number of seconds:";
    cin >> second;
    cout << second << " seconds = " << second / (hours * minutes * seconds) << " days, "
    << second % (hours * minutes * seconds) % (hours) << " hours, "
    << second % (hours * minutes * seconds) << " seconds." << endl;
}