/*
#include <iostream>

class B1 {
public:
	virtual void foo() { std::cout << "B1" << std::endl; }
};

class B2 : public B1 {
public:
	virtual void foo() { std::cout << "B2" << std::endl; }
};

class D : public B2, public B1 {
public:
	void p() { std::cout << "p";}
};

int main() {
	D obj; 
	obj.p();
	dynamic_cast<B2&>(obj).foo();
}

//g++ multipleInheritance.cpp
//multipleInheritance.cpp:13:7: warning: direct base ‘B1’ inaccessible in ‘D’ due to ambiguity [-Winaccessible-base]
//   13 | class D : public B2, public B1 {
//      |       ^
//OUTPUT: pB2
*/

/*
#include <iostream>

class B1 {
public:
	virtual void foo() { std::cout << "B1" << std::endl; }
};

class B2 {
public:
	virtual void foo() { std::cout << "B2" << std::endl; }
};

class D : public B1, public B2 {

};

int main() {
	D obj; //ok
	dynamic_cast<B1&>(obj).foo();
}
//OUTPUT: B1
*/
