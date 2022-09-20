//
// Created by ljx on 2022/9/20.
//
#include<iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream is;
    string fileName = "./a.txt";
    is.open(fileName);
    int character = 0;
    char t;
    is >> t;
    while(!is.eof()){
        cout << t;
        ++character;
        is >> t;
    }
    cout << "total character: " << character << endl;
}