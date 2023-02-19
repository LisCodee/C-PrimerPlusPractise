#include <iostream>

using namespace std;

template <class T>
T maxn(T* ta, int len)
{
    if (len <= 0)
    {   
        return NULL;
    }
    
    T temp = ta[0];
    for(int i = 0; i < len; ++i){
        temp = temp > ta[i] ? temp : ta[i];
    }
    return temp;
}
template<> char* maxn(char* ca[], int len)
{
    char* temp = ca[0];
    for(int i = 0; i < len; ++i)
    {
        temp = strlen(temp) >= strlen(ca[i]) ? temp : ca[i];
    }
    return temp;
}
int main()
{
    int ia[6] = {1,2,3,4,5,6};
    double da[4] = {1., 2., 3., 4.};
    cout << maxn(ia, 6) << endl;
    cout << maxn(da, 4) << endl;
    char* ca[] = {"ab", "a", "abcd", "aaaa"};
    cout << maxn(ca, 4) << endl;
    return 0;
}
