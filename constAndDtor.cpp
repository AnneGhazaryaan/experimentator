//destructors may not be cv-qualified
#include <iostream>

class X {
public:
    X() : _x(new int) {
        std::cout << "Default constructor called.\n";
    }

    ~X() const {
        delete _x;
        std::cout << "Destructor called.\n";
    }

    void setData(int value) {
        *_x = value;
    }

    void displayData() const {
        std::cout << "_x value: " << *_x << "\n";
    }
private:
    int* _x;
};

int main() {
    X myObject;

    myObject.setData(42);
    myObject.displayData();

    return 0;
}
