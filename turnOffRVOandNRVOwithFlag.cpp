//-fno-elide-constructors
#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Default constructor called" << std::endl;
    }

    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called" << std::endl;
    }
    
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }    
};

MyClass g() {
    std::cout << "Greetings from g\n";
    MyClass ob;
    std::cout << "Bye from g\n";
    return ob;
}

int main() {
    MyClass obj = g();
    std::cout << "End of g call\n";
    return 0;
}

