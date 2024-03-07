//time bomb
#include <iostream>

class A {
public:
	virtual void f() { std::cout << "f" << std::endl; }
private:
	int x;
};

class B : public A {
public:
	virtual void g() { std::cout << "g" << std::endl; }
private:
	double x;
};
class C : public A {
public:
	virtual void r() { std::cout << "r" << std::endl; }
private:
	char x;
};

int main() {
	A* ptr = new B();
	ptr = new C();
	B* ptrb = static_cast<B*>(ptr);
	ptrb->g();
}
