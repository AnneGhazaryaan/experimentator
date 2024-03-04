#include <iostream>

class Base {
public:
        virtual void foo() {std::cout << "1"; }
};

class Derived : public Base {
public:
        void foo() override {
                Base::foo();
                std::cout << "2"; 
        }
};

int main() {
        Derived ob;
        ob.foo();
}

/*
#include <iostream>

class Base {
public:
	virtual void foo() {std::cout << "1"; }
};

class Derived : public Base {
public:
	void foo() override {
		foo();
		std::cout << "2"; 
	}
};

int main() {
	Derived ob;
	ob.foo();
}
//Segmentation fault (core dumped)
*/
