#include <iostream>

class Mlass {
public:
	Mlass() : a{2}, b{4} {}
	int getA() const {
		return a;
	}
private:
	int a;
	int b;
};

class Cheating {
public:
	int a;
	int b;
};

int main() {
	Mlass ob;
	Cheating* p = (Cheating*)&ob;
	p->a = 77;
	std::cout << ob.getA();
}	
