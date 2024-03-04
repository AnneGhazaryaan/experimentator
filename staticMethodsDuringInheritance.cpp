//You cannot override static methods
//If you have static methods in your derived class with the same name as a static method in your base class, you actually have 2 separete methods.
#include <iostream>

class Base {
public:
	static void Static() { std::cout << "Base::Static" << std::endl; }
};

class Derived : public Base {
public:
	static void Static() { std::cout << "Derived::Static" << std::endl; }
};

int main() {
	Base::Static();
	Derived::Static();

	Derived obj;
	Base& ref = obj;
	//I know that's not a good practice, but in any case I can
	obj.Static();
	ref.Static();
}

/*
OUTPUT
Base::Static
Derived::Static
Derived::Static
Base::Static
The reason is that C++ doesn’t care what the object actually is when calling a static method. It only cares about the compile-time type. In this case, the type is a reference to a BaseStatic.
*/
