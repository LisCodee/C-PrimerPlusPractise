//
// Created by ljx on 2022/9/21.
//
#include <iostream>
using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void showBox(box b){
    cout << b.maker << endl;
    cout << b.height << endl;
    cout << b.width << endl;
    cout << b.length << endl;
    cout << b.volume << endl;
}

void calVolume(box* b)
{
    b->volume = b->height * b->width * b->length;
}

int main()
{
    box b = {"box", 10, 10, 10, 0};
    showBox(b);
    calVolume(&b);
    showBox(b);
}