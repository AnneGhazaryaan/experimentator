#include <iostream>

class X {
public:
	X(int x, int y) : _x{x}, _y{y} {}
	void print() {
		std::cout << _x << " " << _y << std::endl;
	}
private:
	int _x;
	int _y;
};

void foo(X ob) {
	std::cout << "In foo" << std::endl;
	ob.print();
}

int main() {
	foo({1,2});
	return 0;
}
