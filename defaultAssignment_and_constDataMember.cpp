#include <iostream>

class MyClass {
public:
    MyClass(int value) : myConstValue(value) {}
private:
    const int myConstValue;
};

int main() {
    MyClass obj1(42);
    MyClass obj2(43);
    obj2 = obj1;

    return 0;
}
