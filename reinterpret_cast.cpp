//reinterpret_cast
//You should be careful with reinterpret_cast() because it allows you to do conversions without performing any type checking.

/*
//1
//You can cast a reference to one type to a reference to another type, even if the types are unrelated.
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
        double getD() const { return _d; }
private:
        double _d;
};

int main() {
        Int x(7);
        Double y(9.9);
        Double y2 = reinterpret_cast<Double&>(x);
        Int x2 = reinterpret_cast<Int&>(y);
	std::cout << y2.getD() << std::endl;
	std::cout << x2.getI() << std::endl;
	//It will output garbage, because reinterpreting objects of Int and Double is not safe as they have different memory layouts.
}
*/

/*
//2
//You can cast a pointer type to any other pointer type, even if they are unrelated by an inheritance hierarchy. 
//This is commonly used to cast a pointer to a void*. This can be done implicitly, so no explicit cast is required.
//However, casting a void* back to a correctly typed pointer requires reinterpret_cast().
class X {};
class Y {};

int main() {
	X x;
	Y y;
	X* xp { &x };
	Y* yp { &y };

	// Need reinterpret_cast for pointer conversion from unrelated classes
	// static_cast doesn't work.
	xp = reinterpret_cast<X*>(yp);

	// No cast required for conversion from pointer to void*
	void* p { xp };

	// Need reinterpret_cast for pointer conversion from void*
	//static_cast aslo work.//by me
	xp = reinterpret_cast<X*>(p);

	// Need reinterpret_cast for reference conversion from unrelated classes
	// static_cast doesn't work.
	X& xr { x };
	Y& yr { reinterpret_cast<Y&>(x) };
}
*/

/*
//3.1
//
//You can also use reinterpret_cast() to cast pointers to integral types and back. 
//However, you can only cast a pointer to an integral type that is large enough to hold it. 
//For example, trying to use reinterpret_cast() to cast a 64-bit pointer to a 32-bit integer results in a compilation error.
//Note that casting between pointers and integral types might not be portable across different platforms, and it should be avoided unless there is a specific need and understanding of the underlying memory representation.//by me
#include <iostream>

class Int {
public:
        Int(int val) : data(val) {}
	int get() const { return data; }
private:
        int data;
};

int main() {
        Int obj(42);
        Int* p1 = &obj;

        int* p2 = reinterpret_cast<int*>(p1);
        std::cout << "Pointer value as integer: " << *p2 << std::endl;

        Int* p3 = reinterpret_cast<Int*>(p2);
        std::cout << "Integer cast back to pointer: " << p3->get() << std::endl;

}
//Output
//Pointer value as integer: 42
//Integer cast back to pointer: 42
*/

/*
//3.2
#include <iostream>

int main() {
        // Example: Casting a 64-bit pointer to a 32-bit integer
        long long value = 42;
	long long* ptr64 = &value;

	// Attempting to cast a 64-bit pointer to a 32-bit integer
	// This will result in a compilation error
	// Uncommenting the line below will cause the error
	int* ptr32 = reinterpret_cast<int*>(ptr64);
	std::cout << *ptr64 << " " << *ptr32 << std::endl;
}
//"In the 5th edition of 'Professional C++' by M. Gregory, it is mentioned that the provided code should result in an error. However, when I compile the code using GCC, no error is encountered. I believe this discrepancy might be due to platform and compiler-specific factors."
//Output:
//42 42
*/














