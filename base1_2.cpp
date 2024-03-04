#include <iostream>

class Base1 {
public:
	Base1() : _x{1} {}
private:
	int _x;
};

class Base2 {
public:
	Base2() : _y{2} {}
private:
	int _y;
};

class Derived : public Base1, public Base2 {
public:
	Derived() : _z{3} {}
private:
	int _z;
};

int main() {
	Derived ob;
	Base1* p1 = &ob;
	Base2* p2 = &ob;
	//it's a fake

	std::cout << p1 << std::endl;;
	std::cout << p2 << std::endl;
	std::cout << &ob << std::endl;
}

//Output
//0x7ffec9197fac
//0x7ffec9197fb0
//0x7ffec9197fac

