/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
In C++, you cannot directly assign a pointer to a const-qualified type to a pointer of a non-const-qualified type without a type conversion.
*/

//1
/*
#include <iostream>

void foo(int* p) {
        std::cout << "hi\n";
}

int main() {
        int y = 5;
        const int* p = &y;
        foo(p);
}
*/


//2
/*
#include <iostream>

class X {
public:
	X() : x{}, y{} {}
	int x;
	int y;
};

void foo(const X* ob) {
	std::cout << "Hi from foo" << std::endl;
}

void foo2(X* ob) {
	std::cout << "Hi from foo2" << std::endl;
}

int main() {
	X x1;
	const X x2;
	foo(&x1);
	foo(&x2);
	foo2(&x1);
	foo2(&x2);
}
*/


//3
/*
#include <iostream>

class X {
public:
        X() : x{}, y{} {}
        int x;
        int y;
};

void foo(const X ob) {
        std::cout << "Hi from foo" << std::endl;
}

void foo2(X ob) {
        std::cout << "Hi from foo2" << std::endl;
}
int main() {
        X x1;
        const X x2;
        foo(x1);
        foo(x2);
        foo2(x1);
        foo2(x2);
}
*/
