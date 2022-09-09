//
// Created by ljx on 2022/9/9.
//
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float inch, foot, weight;
    const float foot2meter = 0.0254, lb2kg = 1/2.2, inch2foot = 12;
    cout << "Input your height in inch:";
    cin >> inch;
    cout << "Input your height in foot:";
    cin >> foot;
    cout << "Input your weight in lb:";
    cin >> weight;
    cout << "your BMI is: " << weight*lb2kg / pow((inch*inch2foot+foot)*foot2meter, 2) << endl;
}