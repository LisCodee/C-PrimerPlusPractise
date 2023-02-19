#include<iostream>
#include"golf.h"

void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    std::cout << "Input name:";
    std::string name;
    std::getline(std::cin, name);
    if(name.empty())
        return 0;
    std::cout << "Input hc:";
    int hc;
    std::cin >> hc;
    setgolf(g, name.c_str(), hc);
    return 1;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    std::cout << "fullname:" << g.fullname << "\thc:" << g.handicap << std::endl;
}