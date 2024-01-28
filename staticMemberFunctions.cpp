#include <iostream>

class X {
public:
    X() = default;
    X(int x) : _x(x) {}

    void printState()  { std::cout << "Current state: " << _x << std::endl; }
    static void staticMethod() ;
    static void staticMethod2(X ob);


private:
    int _x;
};

void X::staticMethod() {
    std::cout << "\nHello from a static method!\n";
    X obj;
    obj._x = 1;
    obj.printState();
    std::cout << "You can acces private members in static methods" << std::endl;
}

void X::staticMethod2(X ob) {
    std::cout << "\nHello from a static method!\n";
    ob._x = 2;
    ob.printState();
    std::cout << "You can acces private members in static methods" << std::endl;
}

int main() {
    X obj(42);
    obj.printState();

    X::staticMethod();
    X::staticMethod2(obj);
    return 0;
}
