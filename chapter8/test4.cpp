#include <iostream>
#include <cstring>

using namespace std;

struct stringy{
    char * str;
    int ct;         //length to a string
};

void set(stringy& s, char* cs)
{
    s.ct = strlen(cs);
    s.str = new char[s.ct];
    memcpy(s.str, cs, s.ct);
}

void show(const stringy& s, int repeat=1)
{
    for(int i = 0; i < repeat; ++i)
    {
        cout << s.str << endl;
    }
}

void show(const char* s, int repeat=1)
{
    for(int i = 0; i < repeat; ++i)
    {
        cout << s << endl;
    }
}
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    //first argument is a reference, allocates space to hold copy of testing, sets str member of beany to point 
    //to the new block, copies testing to new block, and sets ct member of beany.
    set(beany, testing);
    show(beany);        //print string onces
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}
