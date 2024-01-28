#include <iostream>

void g(int&& x) {
        std::cout << "g()" << std::endl;
}

void foo(int& x) {
        std::cout << "lvalue" << std::endl;
}

void foo(int&& x) {
        std::cout << "rvalue" << std::endl;
	g((int&&)x);
}

int main() {
        int x = 9;
        foo(x);
        foo(9);
        foo(x + 9);
}
