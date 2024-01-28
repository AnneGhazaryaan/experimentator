//In the double constructor explicitly called a constructor that takes an integer and becuse of this created a temporary object. The temporary object mistakenly initialized instead of the intended one.
#include <iostream>

class X {
public:	
	X(int x) : _x{x} {
		std::cout << "Hello from int ctor" << std::endl;
	}
	X(double d) {
		std::cout << "Hello from double ctor" << std::endl;
		X(static_cast<int>(d));
	}
	void print() {
		std::cout << _x << std::endl;
	}
private:
	int _x;
};

int main() {
	X ob(7.5);
	ob.print();
	return 0;
}
