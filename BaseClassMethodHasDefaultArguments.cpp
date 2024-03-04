#include <iostream>

class Base {
public:
	virtual void f(int i = 9) { std::cout << i << std::endl;}
};

class Derived : public Base {
public:
	void f(int i = 0) override { std::cout << i << std::endl;}
};

int main() {
	Base ob;
	Derived obj;
	Base& ref = obj;

	ob.f();
	obj.f();
	ref.f();
}
/*
OUTPUT
9
0
9
The reason for this behavior is that C++ uses the compile-time type of the expression to bind default arguments, not the run-time type.
*/

/*
//Default arguments are not “inherited” in C++
//So this give an error
#include <iostream>

class Base {
public:
        virtual void f(int i = 9) { std::cout << i << std::endl;}
};

class Derived : public Base {
public:
        void f(int i) override { std::cout << i << std::endl;}
};

int main() {
        Base ob;
        Derived obj;
        Base& ref = obj;

        ob.f();
        //obj.f();//error
        ref.f();
}
*/
