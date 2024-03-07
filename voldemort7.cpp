/*
#include <iostream>

struct A {
public:
	void f() { std::cout << 1; }
};

class B : A {};

int main() {
	B ob;
	ob.f();
}
voldemort7.cpp: In function ‘int main()’:
voldemort7.cpp:12:13: error: ‘void A::f()’ is inaccessible within this context
   12 |         ob.f();
      |         ~~~~^~
voldemort7.cpp:5:14: note: declared here
    5 |         void f() { std::cout << 1; }
      |              ^
voldemort7.cpp:12:13: error: ‘A’ is not an accessible base of ‘B’
   12 |         ob.f();
      |         ~~~~^~
*/
/*
#include <iostream>

struct A {
public:
        void f() { std::cout << 1; }
};

class B : public A {};

int main() {
        B ob;
        ob.f();
}
*/

#include <iostream>

class A {
public:
        void f() { std::cout << 1; }
};

struct B : A {};

int main() {
        B ob;
        ob.f();
}

