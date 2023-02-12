#include<iostream>

void strcount(const std::string str);

int main()
{
    using namespace std;
    string input;
    char next;
    cout << "Enter a line:" << endl;
    getline(cin, input);
    while(cin)
    {
        // cin.get(next);
        strcount(input);
        cout << "Enter next line(empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye!" << endl;
}

void strcount(const std::string str)
{
    if(str.empty())
        exit(0);
    std::cout << "len of str:" << str.size() << std::endl;
}