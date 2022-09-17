//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<string>

using namespace std;

struct Car{
    string manu;
    int year;
};

int main()
{
    int nums;
    cout << "How many cars do you wish to catalog?";
    cin >> nums;
    cin.get();
    Car* cars = new Car[nums];
    for(int i = 0;i < nums; ++i){
        cout << "Car #" << i+1 << endl;
        cout << "Please enter the make:";
        getline(cin, cars[i].manu);
        cout << "Please enter the year:";
        cin >> cars[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for (int i = 0; i < nums; ++i) {
        cout << cars[i].year << "\t" << cars[i].manu << endl;
    }
}