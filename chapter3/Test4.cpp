//
// Created by ljx on 2022/9/9.
//

#include<iostream>
using namespace std;

int main()
{
    long lsecond;
    const short hours = 24, minutes = 60, seconds = 60;
    cout << "Enter the number of seconds:";
    cin >> lsecond;
    int day, hour, minute, second;
    day = lsecond / (hours * minutes * seconds);
    hour = lsecond % (hours * minutes * seconds) / (minutes * seconds);
    minute = lsecond % (hours * minutes * seconds) % (minutes * seconds) / (seconds);
    second = lsecond % (hours * minutes * seconds) % (minutes * seconds) % (seconds);
    cout << lsecond << " seconds = " << day << " days, "
    << hour << " hours, " << minute << " minutes, "
    << second << " seconds." << endl;
}