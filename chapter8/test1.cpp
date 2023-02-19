#include <iostream>

int callNum = 0;

void printString(std::string* s, int num=0)
{
    if(num == 0)
        std::cout << *s << std::endl;
    else
    {
        for(int i = 0; i < callNum; ++i)
        {
            std::cout << *s << std::endl;
        }
    }
    ++callNum;
}
int main()
{
    std::string s = "aaaaaa";
    printString(&s);
    printString(&s);
    printString(&s);
    std::cout << std::endl;
    printString(&s, 1);
    return 0;
}