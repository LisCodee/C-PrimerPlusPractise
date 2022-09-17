//
// Created by ljx on 2022/9/17.
//

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    const int Size = 128;
    char firstName[Size], lastName[Size];
    cout << "Enter your first name:" ;
    cin.getline(firstName, Size);
    cout << "Enter your last name:";
    cin.getline(lastName, Size);
    strcat(lastName, ", ");
    strcat(lastName, firstName);
    cout << "Here's the information in a single string: " << firstName << endl;
}