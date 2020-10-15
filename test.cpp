#include <iostream>
#include "in.h"
using namespace std;

struct A
{
    char a:4;
    char b:4;
    unsigned short i:8;
};
int main(int argc, char **argv)
{
    int i = -21;
    cout << (i % 10) << " " << (i / 10) << endl;
    return 0;
}

