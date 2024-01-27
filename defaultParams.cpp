//Default values for function parameters should be specified only in the declaration or definition, not both.
/*
#include <iostream>
#include <string>

class MyClass {
public:
    MyClass();
    void displayMessage(std::string message = "Hello, World!");
};

MyClass::MyClass() {
    std::cout << "Default constructor called." << std::endl;
}

void MyClass::displayMessage(std::string message) {
    std::cout << message << std::endl;
}

int main() {
    MyClass myObject;
    myObject.displayMessage();
    myObject.displayMessage("Custom message");

    return 0;
}
*/

/*
#include <iostream>
#include <string>

class MyClass {
public:
    MyClass();
    void displayMessage(std::string message);
};

MyClass::MyClass() {
    std::cout << "Default constructor called." << std::endl;
}

void MyClass::displayMessage(std::string message = "Hello, World!") {
    std::cout << message << std::endl;
}

int main() {
    MyClass myObject;
    myObject.displayMessage();
    myObject.displayMessage("Custom message");

    return 0;
}
*/

/*
#include <iostream>
#include <string>

class MyClass {
public:
    MyClass();
    void displayMessage(std::string message = "Hello, World!");
};

MyClass::MyClass() {
    std::cout << "Default constructor called." << std::endl;
}

void MyClass::displayMessage(std::string message = "Hello, World!") {
    std::cout << message << std::endl;
}

int main() {
    MyClass myObject;
    myObject.displayMessage();
    myObject.displayMessage("Custom message");

    return 0;
}
*/
