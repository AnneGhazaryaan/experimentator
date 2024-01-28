//Error!
//gcc says
//MyInt operator+(const MyInt&, const MyInt&)’ must have an argument of class or enumerated type

#include <iostream>

typedef int MyInt;

MyInt operator+(const MyInt& a, const MyInt& b) {
    return a + b;
}

int main() {
    MyInt a = 5;
    MyInt b = 10;
    MyInt result = a + b;
    std::cout << "Result: " << result << std::endl;
    return 0;
}
