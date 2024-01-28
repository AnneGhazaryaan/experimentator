//A nested class has access to all protected and private members of the outer class. 
//The outer class on the other hand can only access public members of the nested class.
//In this example, class B is simply declared in the class A and it does not affect the size of the A's instances

#include <iostream>

class A {
public:
	A() : b{} {}
	class B {
	public:
		void fx();
	private:
		int x;
	};
private:
	int b;
};

void A::B::fx() {
	A ob;
	std::cout << ob.b << std::endl;

}

int main() {
	A ob;
	A::B obj;
	obj.fx();
	std::cout << sizeof(ob) << std::endl;
	std::cout << sizeof(obj) << std::endl;
}
