//Use downcasting only when really necessary, and be sure to use dynamic_cast().
//If function only really works with Derived objects, so instead of accepting a Base pointer, it should simply accept a Derived pointer. This eliminates the need for any downcasting. If the function should work with different derived classes, all inheriting from Base, then look for a solution that uses polymorphism.


#include <iostream>

class B {
public:
	B() : _x{0} {}
	virtual void print() { std::cout << "1"; }
	int getX() const { return _x; }
private:
	int _x;
};

class D : public B {
public:
	D() : _y{0} {}
	int getY() const { return _y; }
private:
	int _y;
};

void foo(B* ptr) {
	D* ptr2 = dynamic_cast<D*>(ptr);
	if (ptr2 != nullptr) {
		std::cout << ptr2->getY() << std::endl;
	} else {
		std::cout << "Novu" << std::endl;
	}
}

int main() {
	D obj;
	foo(&obj);
	B ob;
	foo(&ob);
}


/*
#include <iostream>

class B {
public:
        B() : _x{0} {}
        int getX() const { return _x; }
private:
        int _x;
};

class D : public B {
public:
        D() : _y{0} {}
        int getY() const { return _y; }
private:
        int _y;
};

void foo(B* ptr) {
        D* ptr2 = static_cast<D*>(ptr);
        std::cout << ptr2->getY() << std::endl;
}

int main() {
        //D obj;
        //foo(&obj); //fine
        B ob;
        foo(&ob);//undefined behaviour
}
*/

