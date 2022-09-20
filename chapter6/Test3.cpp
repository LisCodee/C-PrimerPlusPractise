//
// Created by ljx on 2022/9/20.
//
#include<iostream>

using namespace std;
int main()
{
    char in;
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\t p) pianist " << endl;
    cout << "t) tree\t g) game" << endl;
    cin >> in;
    while (true)
    {
        switch (in) {
            case 'c':
                cout << "A maple is a carnivore " << endl;
                break;
            case 'p':
                cout << "A maple is a pianist " <<endl;
                break;
            case 't':
                cout << "A maple is a tree" << endl;
                break;
            case 'g':
                cout << "A maple is a game" << endl;
                break;
            default:
                cout << "Please enter a c, p, t or g:";
        }
        cin >> in;
    }
}