#include <iostream>

class A {
	char c;
};

class B : public A {};

int main() {
	A ob;
	B obj;
	std::cout << sizeof(ob) << std::endl;
	std::cout << sizeof(obj) << std::endl;
}
/*
OUTPUT:
1
1
*/
