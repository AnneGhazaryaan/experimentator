#include <iostream>

class MyClass {
public:
    void getCellAt(int x, int y) {
        std::cout << "Non-const getCellAt: " << x << ", " << y << "\n";
    }

    void getCellAt(int x, int y) const = delete;
};

int main() {
    MyClass obj;
    obj.getCellAt(3, 4);

    const MyClass constObj;
    constObj.getCellAt(3, 4);  // This line would result in a compilation error

    return 0;
}











/*
#include <iostream>
#include <type_traits>

// Function template
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printNumber(T number) {
    std::cout << "Integral number: " << number << std::endl;
}

// Deleted overload for non-integral types
template <typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
printNumber(T number) = delete;

int main() {
    printNumber(42);   // Calls the first overload for integral types
    printNumber("Hello");  // This line would result in a compilation error

    return 0;
}
*/
