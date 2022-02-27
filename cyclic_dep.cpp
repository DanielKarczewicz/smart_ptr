#include <iostream>
#include <memory>

/*
        b_out ---> b1<--|
                    |   |
                    |   |
                    v   |
                    b2--|
*/

struct B {
    B(int x) : x(x) {std::cout << "ctor of object no " << x << '\n';}
    int x;
    std::shared_ptr<B> next_obj;
    ~B() {std::cout << "dtor of object no " << x << '\n';}
};


int main() {
    auto b1 = std::make_shared<B>(1);
    auto b2 = std::make_shared<B>(2);
    b1->next_obj = b2;
    b2->next_obj = b1;
    {
        auto b_out = b1;
        std::cout << "b1 count = " << b1.use_count() << '\n';
    }
    
    


    std::cout << "b1 count = " << b1.use_count() << '\n';
    std::cout << "b2 count = " << b2.use_count() << '\n';
}