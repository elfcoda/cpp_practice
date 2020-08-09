#include <iostream>
using namespace std;

void f1(int& x)
{
    cout << "lllll" << endl;
}

void f1(int&& x)
{
    cout << "rrrrr" << endl;
}

int main()
{
    int i = 9;
    f1(i);
    return 0;
}
