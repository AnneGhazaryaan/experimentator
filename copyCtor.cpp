#include <iostream>

class MyClass {
public:
    MyClass() : _x(0), _y(0) {
        std::cout << "Hello from default constructor\n";
    }

    MyClass(const MyClass& src) : _x(src._x), _y(src._y) {
        std::cout << "Hello from copy constructor\n";
    }

    ~MyClass() {
        std::cout << "Hello from destructor\n";
    }

private:
    int _x;
    int _y;
};

void foo1(const MyClass& obj) {
    std::cout << "Greetings from foo1\n";
}

void foo2(MyClass obj) {
    std::cout << "Greetings from foo2\n";
}

int main() {
    MyClass obj;
    
    foo1(obj);
    std::cout << "End of foo1 call\n\n";
    
    foo2(obj);
    std::cout << "End of foo2 call\n\n";
    return 0;
}

/*
Output:
Hello from default constructor
Greetings from foo1
End of foo1 call

Hello from copy constructor
Greetings from foo2
Hello from destructor
End of foo2 call

Hello from destructor
*/
