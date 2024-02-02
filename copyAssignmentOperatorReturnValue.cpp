/*
It is functional, but I encounter unnecessary duplicates. It would be more optimal to return X&. However, for certain scenarios, it is advisable to return const X&, as exemplified in cases like:
(ob3 = ob2) = ob;
*/
#include <iostream>

class X {
public:
	X() = default;
	X(int x) :_x{x} {}
	X operator=(const X& rhs) {
		 _x = rhs._x;
		return *this;
	}
	int getX() { return _x;}
private:
	int _x;
};

int main() {
	X ob1(4);
	X ob2;
	X ob3;
	ob3 = ob2 = ob1;
	std::cout << ob3.getX() << std::endl;
	return 0;
}
