//
// Created by ljx on 2022/9/20.
//
#include<iostream>

using namespace std;

const short strsize = 128;
struct bop{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    short preference;       //0 = fullname, 1 = title, 2 = bopname
};
void showFullname(bop bops[], int length){
    for (int i = 0; i < length; ++i) {
        cout << bops[i].fullname << endl;
    }
}
void showTitle(bop bops[], int length){
    for (int i = 0; i < length; ++i) {
        cout << bops[i].title << endl;
    }
}
void showBopname(bop bops[], int length){
    for (int i = 0; i < length; ++i) {
        cout << bops[i].bopname << endl;
    }
}
void showPreference(bop bops[], int length){
    for (int i = 0; i < length; ++i) {
        switch (bops[i].preference) {
            case 0:
                cout << bops[i].fullname << endl;
                break;
            case 1:
                cout << bops[i].title << endl;
                break;
            case 2:
                cout << bops[i].bopname << endl;
        }
    }
}
int main()
{
    bop bops[3] {{"Wimp Macho", "Teacher", "aaa", 1},
                 {"Raki Rhodes", "Student", "bbb", 2},
                 {"Celia Laiter", "Pro", "ccc", 0}};
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "q. quit" << endl;
    char in;
    cin >> in;
    while(cin.good())
    {
        switch (in) {
            case 'a':
                showFullname(bops, 3);
                break;
            case 'b':
                showTitle(bops, 3);
                break;
            case 'c':
                showBopname(bops, 3);
                break;
            case 'd':
                showPreference(bops, 3);
                break;
            case 'q':
                exit(0);
        }
        cin >> in;
    }
}