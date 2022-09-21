//
// Created by ljx on 2022/9/21.
//
#include <iostream>
using namespace std;

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n)
{
    int len;
    for (int i = 0; i < n && cin.good(); ++i) {
        ++len;
        cout << "Input the full name:";
        cin.getline(pa[i].fullname, SLEN);
        cout << "Input the hobby:";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Input the ooplevel:";
        cin >> pa[i].ooplevel;
        cin.get();
    }
    return len;
}

void display1(student st)
{
    cout << st.fullname << "\t" << st.hobby << "\t" << st.ooplevel << endl;
}

void display2(const student* st)
{
    cout << st->fullname << "\t" << st->hobby << "\t" << st->ooplevel << endl;
}

void display3(const student st[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << st[i].fullname << "\t" << st[i].hobby << "\t" << st[i].ooplevel << endl;
    }
}

int main()
{
    cout << "Enter class size:";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        continue;

    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; ++i) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done" << endl;
    return 0;
}