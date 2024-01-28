#include <iostream>
class Foo;
//void printFoo(const Foo&);

class Foo {
public:
	Foo(int x) : _x{x} {}
	friend void printFoo(const Foo&);
private:
	int _x;
};

void printFoo(const Foo& ob) {
	std::cout << ob._x << std::endl;
}

int main() {
	Foo obj(5);
	printFoo(obj);
	return 0;
}
