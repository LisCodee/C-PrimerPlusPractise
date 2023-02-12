#include<iostream>
struct chaff
{
    char dross[20];
    int slag;
};

chaff temp[20];

int main()
{
    using namespace std;
    chaff* chaffs = new (temp) chaff[2];
    strcpy(chaffs[0].dross, "aaaaa");
    chaffs[0].slag = 1;
    strcpy(chaffs[1].dross, "bbb");
    chaffs[1].slag = 2;
    for(int i = 0; i < 2; ++i)
    {
        cout << "chaff1:" << chaffs[i].dross << "\tslag:" << chaffs[i].slag << endl;
    }
    return 0;
}