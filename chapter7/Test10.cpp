//
// Created by ljx on 2022/9/22.
//
#include <iostream>
using namespace std;

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mul(double x, double y)
{
    return x * y;
}

double calculate(double a, double b, double (*pf)(double, double))
{
    return (*pf)(a, b);
}

int main()
{
    double (*pf[3])(double, double) {add, sub, mul};
    double x, y;
    cout << "Input two numbers(eg:2.1 3.1):";
    while(cin >> x >> y){
        cout << "add:" << calculate(x, y, pf[0]) << endl;
        cout << "sub:" << calculate(x, y, pf[1]) << endl;
        cout << "mul:" << calculate(x, y, pf[2]) << endl;
        cin.get();
        cout << "Input two numbers(eg:2.1 3.1):";
    }
}

