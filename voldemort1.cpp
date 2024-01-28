#include <iostream>

class FirstClass {
public:
    FirstClass(int value) : data(value) {}
    void display() const {
        std::cout << "Data in FirstClass: " << data << std::endl;
    }

private:
    int data;
};

class SecondClass {
public:
    static FirstClass staticInstance;
    SecondClass(int value) {
        staticInstance = FirstClass(value);
    }

    static void displayStaticInstance() {
        std::cout << "Static Instance in SecondClass: ";
        staticInstance.display();
    }
};

FirstClass SecondClass::staticInstance = FirstClass(0);

int main() {
    SecondClass obj1(42);
    SecondClass::displayStaticInstance();

    return 0;
}
