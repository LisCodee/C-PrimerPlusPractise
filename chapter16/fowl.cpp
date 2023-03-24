#include<memory>
#include<string>
#include<iostream>

using namespace std;

void test1()
{
    auto_ptr<string> film[5] = {
        auto_ptr<string> (new string("Fow balks")),
        auto_ptr<string> (new string("Fow balks1")),
        auto_ptr<string> (new string("Fow balks2")),
        auto_ptr<string> (new string("Fow balks3")),
        auto_ptr<string> (new string("Fow balks4"))
    };
    auto_ptr<string> pwin;
    pwin = film[2];         //film[2] loses the ownership
    cout << "---------------------" << endl;
    for(int i = 0; i < 5; ++i)
        cout << *film[i] << endl;       // segmentation fault
    cout << "*pwin" << *pwin << endl;
}

unique_ptr<string> getUniquePtr()
{
    unique_ptr<string> ups(new string("aaa"));
    return ups;
}

void test2()
{
    unique_ptr<string> res = getUniquePtr();
    cout << "getUniquePtr:" << *res << endl;
    unique_ptr<string> ups = unique_ptr<string> (new string("bbb"));
    unique_ptr<string> ups1(new string("ccc")), ups2;
    ups2 = std::move(ups1);
    ups1 = unique_ptr<string> (new string("eee"));
    cout << "ups:" << *ups << endl;
    cout << "ups1:" << *ups1 << "\tups2:" << *ups2 << endl;
}
int main()
{
    test2();
}