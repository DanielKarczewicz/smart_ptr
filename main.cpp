#include <iostream>
#include <memory>

struct A {
    int u;
    A(int u) : u(u)  {std::cout << "ctor A\n";}
    ~A() {std::cout << "dtor A\n";}
};

void f(std::unique_ptr<A> p) {
    std::cout << p->u << '\n';
}

int main() {
    
    auto ptr = std::unique_ptr<A>(new A(123));
    
    f(std::move(ptr));
}