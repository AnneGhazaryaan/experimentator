//static_cast
/*
//1
//You can use static_cast() to perform explicit conversions that are supported directly by the language
#include <iostream>

int main() {
	int i { 3 };
	int j { 4 };
	double result { static_cast<double>(i) / j };
}
*/

/*
//2
//You can use static_cast() to perform explicit conversions that are allowed because of user-defined constructors or conversion routines
#include <iostream>

class Int {
public:
	Int(int i) : _i{i} {}
	int getI() const { return _i; }
private:
	int _i;
};

class Double {
public:
	Double(const Int& ob) :  _d(ob.getI()) {}
	double getD() const { return _d; }
private:
	double _d;
};

int main() {
	Int x(7);
	Double y(9.9);
	Double y2 = static_cast<Double>(x);
	std::cout << y2.getD() << std::endl;
}
*/

/*
//2.2
#include <iostream>

class Double; 

class Int {
public:
    Int(int i) : _i{i} {}
    operator Double() const; 
    int getI() const { return _i; }
private:
    int _i;
};

class Double {
public:
    Double(double d) : _d{d} {}
    double getD() const { return _d; }
private:
    double _d;
};

Int::operator Double() const {
    return Double(static_cast<double>(_i));
}

int main() {
    Int x(7);
    Double y(9.9);
    Double y2 = static_cast<Double>(x);
    std::cout << y2.getD() << std::endl;
}
*/

/*
//3
//You can use static_cast() to perform downcasts in an inheritance hierarchy
//REMEMBER! To perform the cast safely with run-time type checking, use dynamic_cast()
#include <iostream>

class Base {
public:
	virtual ~Base() = default;
};
class Derived : public Base {
public:
	virtual ~Derived() = default;
};

int main() {
	Base* b { nullptr };
	Derived* d { new Derived{} };
	
	b = d; // Don't need a cast to go up the inheritance hierarchy.
	d = static_cast<Derived*>(b); // Need a cast to go down the hierarchy.
	
	Base base;
	Derived derived;
	
	Base& br { derived };
	Derived& dr { static_cast<Derived&>(br) };
}
*/

/*
static_cast() is not all-powerful. 
You can’t static_cast() pointers of one type to pointers of another unrelated type. 
You can’t directly static_cast() objects of one type to objects of another type if there is no converting constructor available. 
You can’t static_cast() a const type to a non-const type. 
You can’t static_cast() pointers to ints. 
Basically, you can’t do anything that doesn’t make sense according to the type rules of C++.
*/

















/*
#include <iostream>

class Int {
public:
        Int(int i) : _i{i} {}
        int getI() const { return _i; }
private:
        int _i;
};

class Double {
public:
        Double(double d) : _d{d} {}
        //Double(const Int& ob) :  _d(ob.getI()) {}
        double getD() const { return _d; }
private:
        double _d;
};

int main() {
        Int x(7);
        Double y(9.9);
        //Double y2 = static_cast<Double>(x);
        Double y2 = reinterpret_cast<Double&>(x);
        Int x2 = reinterpret_cast<Int&>(y);
        int xx = 5;
        double yy = reinterpret_cast<int>(xx);
}


*/
