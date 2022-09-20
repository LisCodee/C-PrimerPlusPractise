//
// Created by ljx on 2022/9/20.
//
#include<iostream>
#include <cctype>

int main()
{
    using namespace std;
    char in;
    while((in = cin.get()) != '@'){
        if(isdigit(in))
            continue;
        if(islower(in))
        {
            in = toupper(in);
            cout << in;
        }
        else if(isupper(in))
        {
            in = tolower(in);
            cout << in;
        }
    }
}