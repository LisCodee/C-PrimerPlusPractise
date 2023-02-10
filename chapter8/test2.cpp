#include <iostream>

using namespace std;

struct CandyBar
{
    char* brandName;
    float weight;
    int heat;
};

void setCandyBar(CandyBar& candy, char* brandName="Millennium Munch", float weight=2.85, int heat=350)
{
    candy.brandName = brandName;
    candy.weight = weight;
    candy.heat = heat;
}

void showCandyBar(const CandyBar& candy)
{
    cout << "brand:" << candy.brandName << "\tweight:" << candy.weight << "\theat:" << candy.heat << endl;
}

int main()
{
    CandyBar c;
    setCandyBar(c);
    showCandyBar(c);
    return 0;
}