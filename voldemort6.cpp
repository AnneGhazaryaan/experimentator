#include <iostream> 
#include <typeinfo>

class X {};
class Y : public X {};

class A {
public:
	virtual X* f() { 
		std::cout << "A::f" << std::endl; 
		X* ptr = new X; 
		return ptr; 
	}
};

class B : public A {
public:
	Y* f() override { 
		std::cout << "B::f" << std::endl; 
		Y* ptr = new Y;
		return ptr;
	}
};

int main() {
	B ob;
	A* ptr = &ob;

	ptr->f();
	
	auto v = ptr->f();
	const std::type_info& t = typeid(v);
	std::cout << t.name() << std::endl;	
}

//OUTPUT:
//B::f
//B::f
//P1X
