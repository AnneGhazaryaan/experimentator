/*
#include <iostream>

class A {
public:
	A(int a) : _a{a} {std::cout << "hi" << std::endl;}
private:
	int _a;
};

class B {
	inline static A a{4};
};

int main() {
	B ob;
	return 0;
}
*/

//or
#include <iostream>

class A {
public:
	A(int a) : _a{a} {std::cout << "hi" << std::endl;}
private:
	int _a;
};

class B {
	static A a;
};

A B::a{4};
//A B::a(4);
//A B::a = A(7);

int main() {
	B ob;
	return 0;
}
