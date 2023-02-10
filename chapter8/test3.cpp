#include <iostream>

using namespace std;

int main()
{
    string input;
    cout << "Enter a string(q to quit):" ;
    cin >> input;
    while(input != "q" && input != "quit")
    {
        for(int i = 0; i < input.length(); ++i)
        {
            putchar(toupper(input[i]));
        }
        cout << "\nNext string(q to quit):" ;
        cin >> input;
    }
    cout << "Bye!" << endl;
    return 0;
}
