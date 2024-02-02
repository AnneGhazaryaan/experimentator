#include <iostream>

class A {
public:
	void foo() { 
		std::cout << "hi" << std::endl; 
		x=4; //This give an error
	}
private:
	int x;
	int y;
};

int main() {
	A* ptr = nullptr;
	ptr->foo(); //This equivalent to foo(ptr), so there is no any dereferencig. If I don't try to modify the object this won't give an any errors.

	return 0;
}
