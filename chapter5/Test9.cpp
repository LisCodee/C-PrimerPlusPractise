//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<string>
using namespace std;

int main()
{
    const int size = 128;
    int sum;
    string word;
    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while(word != "done") {
        ++sum;
        cin >> word;
    }
    cout << "You enterd a total of " << sum << " words." << endl;
    return 0;
}