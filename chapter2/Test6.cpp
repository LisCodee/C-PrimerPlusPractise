//
// Created by ljx on 2022/9/8.
//

#include<iostream>

double lightYear2Astro(double lightYear)
{
    return 63240*lightYear;
}
int main()
{
    using namespace std;
    double lightYear;
    cout << "Enter the number of light years:\t";
    cin >> lightYear;
    cout << lightYear << " light years = " << lightYear2Astro(lightYear) << " astronomical units." << endl;
}