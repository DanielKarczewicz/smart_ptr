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

void f_ref(const A &p) {
    std::cout << p.u << '\n';
}

int main() {
    
    auto ptr = std::unique_ptr<A>(new A(123));
    f(std::move(ptr));
    std::cout << "after void f(...)\n";
    std::cout << "======================\n";
    auto ptr_b = std::unique_ptr<A>(new A(777));
    f_ref(*ptr_b);
    std::cout << "after void f_ref(...)\n";

    // A *a = new A(1);
    // auto ptr_c1 = std::unique_ptr<A>(a);
    // auto ptr_c2 = std::unique_ptr<A>(a);

    std::cout << "======================\n";

    auto sh1 = std::make_shared<A>(8);
    std::shared_ptr<A> sh2 (sh1);


}