//examples are given that are the result of Anahit’s imagination

//3
// 'this' is returned to allow chaining of member functions
#include <iostream>

class X {
public:
	X(int x) { this->x = x; }
	X* setvalue(int x) {
		this->x = x;
		return this;
	}
	void print() {
		std::cout << x << std::endl;
	}
private:
	int x;
};

int main() {
	X x1(4);
	x1.print();
	x1.setvalue(5)->print();
	return 0;
}

/*
//2
#include <iostream>

class X {
public:
	void printPtrOfCuurenObj() {
		std::cout << this << std::endl;
	}
};

int main() {
	X x;
	X x2;
	X x3;

	x.printPtrOfCuurenObj();
	x2.printPtrOfCuurenObj();
	x3.printPtrOfCuurenObj();

	return 0;
}
*/

/*
//1
#include <iostream>

class X;

void print(const X& obj);

class X {
public:
	X(int x, int y) : _x(x), _y{y} {}
	int getX() const { return _x;}
	int getY() const { return _y;}
	void printOb() const { print(*this); }
private:
	int _x;
	int _y;
};

void print(const X& obj) {
	std::cout << obj.getX() << " " << obj.getY() << std::endl;
}

int main() {
	X ob(2,4);
	ob.printOb();
	print(ob);
	return 0;
};
*/
