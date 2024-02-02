//There is a memory leak
#include <iostream>

class X {
public:
        X(int x, int y) : _x{x}, _y{y} { std::cout << "In ctor" << std::endl;}
        void print() { std::cout << _x << " " << _y << std::endl;}
        ~X() { std::cout << "In dtor" << std::endl;}
private:
        int _x;
        int _y;
};

void foo(X* ob) {
        std::cout << "In foo" << std::endl;
        ob->print();
	X* ptr = new X(2,3);
}

int main() {
        X* ptr = new X(4,5);
	foo(ptr);
	delete ptr;
	return 0;
}

