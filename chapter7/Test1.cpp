//
// Created by ljx on 2022/9/20.
//

#include <iostream>

double average(double a, double b)
{
    if ((a + b) != 0){
        return 2*a*b/(a+b);
    }
    return NULL;
}
int main()
{
    double x,y;
    using namespace std;
    cout << "input two numbers(sep with space):";
    cin >> x;
    cin >> y;
    while(x!=0 && y!=0 && cin.good()){
        double res;
        if((res = average(x,y)) != NULL)
            cout << res << endl;
        else
            cout << "Input error" << endl;
        cout << "input two numbers(sep with space):";
        cin >> x;
        cin >> y;
    }
    return 0;
}