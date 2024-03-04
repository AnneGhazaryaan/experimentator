/*
#include <iostream>

class X {
	int x;
};

class Y : public X {
	char c;
};

class A {
public:
	virtual X foo() {
		std::cout << "A";
		X ob;
		return ob;
	}
};

class B : public A {
public:
	Y foo() override {
		std::cout << "B";
		Y ob;
		return ob;
	}
};

int main() {}
//overridenMethodReturnType.cpp:22:11: error: invalid covariant return type for ‘virtual Y B::foo()’
//   22 |         Y foo() override {
//      |           ^~~
//overridenMethodReturnType.cpp:13:19: note: overridden function is ‘virtual X A::foo()’
//   13 |         virtual X foo() {
//      |                   ^~~
*/

/*
//It's ok
#include <iostream>

class X {
	int x;
};

class Y : public X {
	char c;
};

class A {
public:
	virtual X* foo() {
		std::cout << "A";
		X* ptr = new X;
		return ptr;
	}
};

class B : public A {
public:
	Y* foo() override {
		std::cout << "B";
		Y* ptr = new Y;
		return ptr;
	}
};

int main() {}
*/

/*
#include <iostream>
#include <memory>

class X {
	int x;
};

class Y : public X {
	char c;
};

class A {
public:
	virtual std::unique_ptr<X> foo() {
		std::cout << "A";
		std::unique_ptr<X> ptr = std::make_unique<X>();
		return ptr;
	}
};

class B : public A {
public:
	std::unique_ptr<Y> foo() override {
		std::cout << "B";
		std::unique_ptr<Y> ptr = std::make_unique<Y>();
		return ptr;
	}
};

int main() {}
//overridenMethodReturnType.cpp:94:28: error: invalid covariant return type for ‘virtual std::unique_ptr<Y> B::foo()’
//   94 |         std::unique_ptr<Y> foo() override {
//      |                            ^~~
//overridenMethodReturnType.cpp:85:36: note: overridden function is ‘virtual std::unique_ptr<X> A::foo()’
//   85 |         virtual std::unique_ptr<X> foo() {
*/
