#include <iostream>
#include "in.h"
using namespace std;

// auto p = std::make_unique<D>(); // p is a unique_ptr that owns a D
// auto q = pass_through(std::move(p));
// assert(!p); // now p owns nothing and holds a null pointer
// q->bar();   // and q owns the D object

struct A
{
    int i;
};

int func(const std::shared_ptr<const A>&  p)
{
    p->i = 8;
    return p->i;
}

int main()
{
    auto sp = std::make_shared<A>();
    return 0;
}
