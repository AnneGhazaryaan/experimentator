#include <iostream>

class Base {
public:
    Base() { foo(); }
    virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {}
    void foo() override {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Derived derived;
    derived.foo();
    return 0;
}
//Output:
//Base::foo()
//Derived::foo()

