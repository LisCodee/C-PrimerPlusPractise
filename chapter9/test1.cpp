#include <iostream>
#include "golf.h"

using namespace std;

int main()
{
    golf gs[5];
    std::string name;
    int hc, count = 0;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "Input name:";
        std::getline(std::cin, name);
        if(name.empty())
            break;
        std::cout << "Input hc:";
        std::cin >> hc;
        setgolf(gs[i], name.c_str(), hc);
        std::getline(std::cin, name);
        ++count;
    }
    for(int i = 0; i < count; ++i)
    {
        showgolf(gs[i]);
    }
    return 0;
}
