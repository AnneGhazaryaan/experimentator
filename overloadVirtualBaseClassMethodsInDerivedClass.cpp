/*
#include <iostream>

class Base {
public:
	virtual void foo() { std::cout << "1";}
};

class Derived : public Base {
public:
	virtual void foo(int x) { std::cout << "1";}	
};

int main() {
	Derived d;
	d.foo();
}
//This give an error, because
+-------------------+
| vtbl for Base     |
+-------------------+
| &Base::foo        |  // Address of Base::foo()
+-------------------+

+-------------------+
| vtbl for Derived  |
+-------------------+
| &Derived::foo(int)|  // Address of Derived::foo(int)
+-------------------+

*/

/*
#include <iostream>

class Base {
public:
        virtual void foo() { std::cout << "1";}
};

class Derived : public Base {
public:
	using Base::foo;
        virtual void foo(int x) { std::cout << "1";}    
};

int main() {
        Derived d;
        d.foo();
}

//This work correctly because of this
+-------------------+
| vtbl for Base     |
+-------------------+
| &Base::foo        |  // Address of Base::foo()
+-------------------+

+-------------------+
| vtbl for Derived  |
+-------------------+
| &Base::foo        |  // Address of Base::foo(), inherited from Base
+-------------------+
| &Derived::foo(int)|  // Address of Derived::foo(int)
+-------------------+
*/

/*
#include <iostream>

class Base {
public:
        virtual void foo() { std::cout << "1";}
        virtual void foo(int x) { std::cout << "2";}
};

class Derived : public Base {
public:
        void foo(int x) override { std::cout << "2d";}    
};

int main() {
        Derived d;
        d.foo();
        d.foo(3);
}
//This give an error, because
+-------------------+
| vtbl for Base     |
+-------------------+
| &Base::foo        |  // Address of Base::foo()
+-------------------+
| &Base::foo(int)   |  // Address of Base::foo(int)
+-------------------+

+-------------------+
| vtbl for Derived  |
+-------------------+
| &Derived::foo(int)|  // Address of Derived::foo(int), overriding Base::foo(int)
+-------------------+
*/

#include <iostream>

class Base {
public:
        virtual void foo() { std::cout << "1";}
        virtual void foo(int x) { std::cout << "2";}
};

class Derived : public Base {
public:
	using Base::foo;
        void foo(int x) override { std::cout << "2d";}    
};

int main() {
        Derived d;
        d.foo();
        d.foo(3);
}
//This work correctly because of this
+-------------------+
| vtbl for Base     |
+-------------------+
| &Base::foo        |  // Address of Base::foo()
+-------------------+
| &Base::foo(int)   |  // Address of Base::foo(int)
+-------------------+

+-------------------+
| vtbl for Derived  |
+-------------------+
| &Base::foo        |  // Address of Base::foo(), inherited from Base
+-------------------+
| &Derived::foo(int)|  // Address of Derived::foo(int), overriding Base::foo(int)
+-------------------+
