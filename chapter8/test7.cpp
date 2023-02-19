#include <iostream>

using namespace std;

struct debts{
    char name[50];
    double amount;
};

template<class T>
T sumArray(T* arr[], int len)
{
    T* temp = (T*)malloc(sizeof(T*));
    *temp = *arr[0];
    for (int i = 1; i < len; i++)
    {
        *temp += *arr[i];
    }
    return *temp;
}
template<class T>
T sumArray(T arr[], int len)
{
    T temp = arr[0];
    for (int i = 1; i < len; i++)
    {
        temp += arr[i];
    }
    return temp;
}

int main()
{
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima wolfe", 2400.},
        {"Ura Foxe", 1300.},
        {"Iby Stout", 1800.}
    };
    double* pd[3];
    for(int i = 0; i < 3; ++i)
    {
        pd[i] = &mr_E[i].amount;
    }
    cout << "sum of int arr:" << sumArray(things, 6) << endl;
    cout << "sum of double* arr:" << sumArray(pd, 3) << endl;
    return 0;
}
