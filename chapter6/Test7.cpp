//
// Created by ljx on 2022/9/20.
//
#include<iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char word[128];
    int vowels, consonants = 0, others;
    cout << "Enter words(q to quit):" << endl;
    cin >> word;
    while(cin.good()){
        if (!isalpha(word[0]))
        {
            others++;
            cin >> word;
            continue;
        }
        else
        {
            if(strlen(word) == 1 && word[0] == 'q')
                break;
            if(word[0] == 'a' || word[0] == 'e' ||word[0] == 'i' ||word[0] == 'o' ||word[0] == 'u' ||
                    word[0] == 'A' ||word[0] == 'E' ||word[0] == 'I' ||word[0] == 'O' ||word[0] == 'U')
            {
                vowels++;
                cin >> word;
                continue;
            }
            else{
                consonants++;
                cin >> word;
                continue;
            }
        }
    }
    cout << "vowels:" << vowels << endl;
    cout << "consonants:" << consonants << endl;
    cout << "other:" << others << endl;
}