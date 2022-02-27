#include <iostream>
#include <memory>


struct B {
    B() : x(x) {}
    int x;
    std::shared_ptr<B> next_obj;
};


int main() {
    auto b1 = std::make_shared<B>(1);
    auto b2 = std::make_shared<B>(2);
    b1->next_obj = b2;
    b2->next_obj = b1;
}