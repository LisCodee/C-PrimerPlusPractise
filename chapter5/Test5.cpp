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
    int sales[12] {0};
    int sum;
    for (int i = 0; i < 12; ++i) {
        cout << "Input " << months[i] << " sales:";
        cin >> sales[i];
        sum += sales[i];
    }

    for (int i = 0; i < 12; ++i) {
        cout << "sales on " << months[i] << " is:" << sales[i] << endl;
    }
    cout << "Total sales: " << sum << endl;

}