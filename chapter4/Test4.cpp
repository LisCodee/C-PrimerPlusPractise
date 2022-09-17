//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string firstName, lastName, res;
    cout << "Enter your first name:" ;
    getline(cin, firstName);
    cout << "Enter your last name:";
    getline(cin, lastName);
    res = lastName + ", " + firstName;
    cout << "Here's the information in a single string: " << res << endl;
}