//
// Created by ljx on 2022/9/17.
//
#include<iostream>
#include<string>

using namespace std;

struct CandyBar{
    string brand;
    float weight;
    int calories;
};

int main()
{
    CandyBar* snack = new CandyBar[3];
    for(int i = 0;i < 3; ++i){
        snack[i].brand = "Mocha Munch";
        snack[i].weight = 2.3f;
        snack[i].calories = 350;
    }
    for(int i = 0;i < 3; ++i){
        cout << "brand: " <<snack[i].brand << endl;
        cout << "weight: " << snack[i].weight << endl;
        cout << "calories: " << snack[i].calories << endl;
    }
    delete [] snack;
    return 0;
}