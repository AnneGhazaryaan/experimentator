#include <iostream>

class X {
public:
        X() : _x{1}, _y{1} {}
        void print() {
                std::cout << _x << "  " << _y << std::endl;
        }
private:
        int _x = 3;
        int _y = 4;
};

int main() {
        X ob;
        ob.print();
        return 0;
}

/*
Ountpt:
1 1
*/
