//
// Created by ljx on 2022/9/17.
//

#include<iostream>
#include<string>

using namespace std;

struct Pizza{
    string company;
    float diameter;
    float weight;
};

int main()
{
    Pizza* pizza = new Pizza;
    cout << "Enter diameter of the pizza:";
    cin >> pizza->diameter;
    cin.get();
    cout << "Enter company of the pizza:";
    getline(cin, pizza->company);
    cout << "Enter weight of the pizza:";
    cin >> pizza->weight;
    cout << "Pizza:" << endl;
    cout << "company:" << pizza->company << endl;
    cout << "diameter: " << pizza->diameter << endl;
    cout << "weight: " << pizza->weight << endl;
}