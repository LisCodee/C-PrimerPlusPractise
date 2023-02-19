#include <iostream>

using namespace std;

template <typename T>

T max5(T arr[5])
{
    T temp = arr[0];
    for (int i = 0; i < 5; i++)
    {
        temp = arr[i] > temp ? arr[i] : temp;
    }
    return temp;
    
}
int main()
{
    int ia[5] = {1,2,3,4,5};
    double da[5] = {1.2, 2.0, 3.1, 2.3, 2.8};
    cout << max5(ia) << endl;
    cout << max5(da) << endl;
    return 0;
}
