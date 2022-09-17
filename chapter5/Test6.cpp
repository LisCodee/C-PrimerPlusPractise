//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string months[12] {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October",
                       "November", "December"};
    int sales[3][12] {0};
    int sum;
    for(int j = 0; j < 3; ++j){
        for (int i = 0; i < 12; ++i) {
            cout << "Input " << j+1 << "th year " << months[i] << " sales:";
            cin >> sales[j][i];
            sum += sales[j][i];
        }
    }

    for(int j = 0; j < 3; ++j){
        for (int i = 0; i < 12; ++i) {
            cout << "sales on " << j+1 << "th year "  << months[i] << " is:" << sales[j][i] << endl;
        }
    }

    cout << "Total sales: " << sum << endl;

}