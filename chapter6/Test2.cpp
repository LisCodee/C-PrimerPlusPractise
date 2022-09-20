//
// Created by ljx on 2022/9/20.
//
#include<iostream>

using namespace std;
int main()
{
    double donations[10] {0}, average;
    short count, flag;
    cin >> donations[0];
    while(cin.good())
    {
        average += donations[count];
        ++count;
        cin >> donations[count];
    }
    average = average/count;
    cout << "average: " << average << endl;
    for (int i = 0; i < count; ++i) {
        if(donations[i] > average)
            ++flag;
    }
    cout << "There are " << flag << " nums greater than average. " << endl;
}