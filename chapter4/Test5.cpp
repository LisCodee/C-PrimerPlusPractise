//
// Created by ljx on 2022/9/17.
//

#include<iostream>
#include<string>

using namespace std;

int main()
{
    struct CandyBar{
        string brand;
        float weight;
        int calories;
    };
    CandyBar snack {"Mocha Munch", 2.3f, 350};
    cout << "CandyBar" << endl;
    cout << "brand: " <<snack.brand << endl;
    cout << "weight: " << snack.weight << endl;
    cout << "calories: " << snack.calories << endl;
}