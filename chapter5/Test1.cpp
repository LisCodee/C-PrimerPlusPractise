//
// Created by ljx on 2022/9/17.
//
#include<iostream>

using namespace std;

int main()
{
    int little, big, res= 0;
    cout << "Input first integer:";
    cin >> little;
    cout << "Input second integer:";
    cin >> big;
    for (int i = little; i <= big; ++i) {
        res += i;
    }
    cout << "sum between " << little << " and " << big << " is " << res << endl;
    return 0;
}