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
    CandyBar snack[3];
    snack[0] = {"Mocha Munch", 2.3f, 350};
    snack[1] = {"Mocha Munch", 2.3f, 350};
    snack[2] = {"Mocha Munch", 2.3f, 350};
    for(int i = 0;i < 3; ++i){
        cout << "brand: " <<snack[i].brand << endl;
        cout << "weight: " << snack[i].weight << endl;
        cout << "calories: " << snack[i].calories << endl;
    }
}