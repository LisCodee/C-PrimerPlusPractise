//
// Created by ljx on 2022/9/20.
//
#include<iostream>
#include <string>
#include <fstream>
using namespace std;

struct patron{
    string name;
    double money;
};

int main()
{
    int num, flag = 0;
    cout << "Input num of patrons:";
    ifstream is;
    is.open("patrons.txt");
    is >> num;
    patron* patrons = new patron[num];
    is.get();
    for (int i = 0; i < num; ++i) {
        cout << "Input " << i+1 << "th patron's name:";
        getline(is, patrons[i].name);
        cout << "Input " << patrons[i].name << "'s patron:";
        is >> patrons[i].money;
        is.get();
    }
    cout << "Grand Patrons:" << endl;
    for (int i = 0; i < num; ++i) {
        if (patrons[i].money > 10000){
            flag = 1;
            cout << "name:" << patrons[i].name << "\tpatron:" << patrons[i].money << endl;
        }
    }
    if(flag == 0)
        cout << "none" << endl;
    flag = 0;
    cout << "Patrons:" << endl;
    for (int i = 0; i < num; ++i) {
        if (patrons[i].money <= 10000){
            flag = 1;
            cout << "name:" << patrons[i].name << "\tpatron:" << patrons[i].money << endl;
        }
    }
    if(flag == 0)
        cout << "none" << endl;
}