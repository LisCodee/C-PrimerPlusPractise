//
// Created by ljx on 2022/9/17.
//

#include<iostream>
#include<array>

using namespace std;

int main()
{
    array<float, 3> grade;
    for (int i = 0; i < 3; ++i) {
        cout << "Enter " << i << "th score for your 40m race:";
        cin >> grade[i];
    }
    float total = 0.f;
    for (int i = 0; i < 3 ; ++i) {
        total += grade[i];
    }
    cout << "your average score is: " << total / 3.0f << " s." << endl;
}