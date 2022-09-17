//
// Created by ljx on 2022/9/17.
//

#include<iostream>
#include<string>

using namespace std;

struct Stu{
    string firstName;
    string lastName;
    char desireGrade;
    short age;
};

int main()
{
    Stu stu;
    cout << "What is your first name:";
    getline(cin, stu.firstName);
    cout << "What is your last name:";
    getline(cin, stu.lastName);
    cout << "what letter grade do you deserve?";
    cin >> stu.desireGrade;
    cout << "What is your age?";
    cin >> stu.age;

    cout << "Name: " << stu.lastName << ", " << stu.firstName << endl;
    cout << "Grade: " << char(stu.desireGrade + 1) << endl;
    cout << "Age: " << stu.age << endl;
}