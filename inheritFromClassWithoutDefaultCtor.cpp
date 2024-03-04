#include <iostream>

class B {
public: 
	B(int x) : _x{x} {}
	int getX() const { return _x;}
private:
	int _x;
};

class D : public B {
public:
	D() : B(4) {}
};

int main() {
	D ob;
	std::cout << ob.getX() << std::endl;
}
