#include <iostream>

class Base {
public:
	virtual void foo() { std::cout << "Hi" << std::endl; }
};

class Derived : public Base {
protected:
	void foo() override { std::cout << "..." << std::endl; }
};

int main() {
	Base ob;
	Derived obj;
	ob.foo();
	//obj.foo(); //error
	Base* p = &obj;
	p->foo();
}

//OUTPUT:
//Hi
//...


/*
//The previous example redefined the method in the derived class because it wants to display a different message. If you don’t want to change the implementation but instead only want to change the access specification of a method, the preferred way is to simply add a using declaration in the derived class definition with the desired access specification.

#include <iostream>

class Base {
public:
        virtual void foo() { std::cout << "Hi" << std::endl; }
};

class Derived : public Base {
protected:
	using Base::foo;
};

int main() {
        Base ob;
        Derived obj;
        ob.foo();
        //obj.foo(); //error
        Base* p = &obj;
        p->foo();
}
*/


//The only truly useful way to change a method’s access specification is by providing a less restrictive accessor to a protected method

/*
#include <iostream>

class Base {
protected:
        virtual void foo() { std::cout << "Hi" << std::endl; }
};

class Derived : public Base {
public:
        virtual void f() { foo();}
};

int main() {
        Base ob;
        Derived obj;
        obj.f(); 
}

//OUTPUT:
//Hi
*/
/*
//or
#include <iostream>

class Base {
protected:
        virtual void foo() { std::cout << "Hi" << std::endl; }
};

class Derived : public Base {
public:
        virtual void foo() override { std::cout << "Hii" << std::endl; }
};

int main() {
        Base ob;
        Derived obj;
        obj.foo();
	//ob.foo(); //error
	Base* p = &obj;
	//p -> foo(); //error 
}
//OUTPUT:
//Hii
*/
/*
//If you don’t want to change the implementation of the overridden method but only change the access specification, then you can use a using declaration.
#include <iostream>

class Base {
protected:
        virtual void foo() { std::cout << "Hi" << std::endl; }
};

class Derived : public Base {
public:
	using Base::foo;
};

int main() {
        Base ob;
        Derived obj;
        obj.foo();
        //ob.foo(); //error
        Base* p = &obj;
        //p -> foo(); //error 
}
//OUTPUT:
//Hi
*/



