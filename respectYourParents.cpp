//read from bottom to top
/*
#include <iostream>

class Something {
public:
	Something() { std::cout << "2"; }
};

class Base {
public:
	Base(int i) : _i{i} {std::cout  << "1"; }
	int getI() const { return _i;}
private:
	int _i;
};

class Derived : public Base {
public:
	Derived(int j, int i) : _j(j),  Base(i) { std::cout << "3"; }
	int getJ() const { return _j;}
private:
	Something s;
	int _j;
};

int main() {
	Derived d(5,6);
	std::cout << std::endl;
	std::cout << d.getI() << std::endl;
	std::cout << d.getJ() << std::endl;
}
//OUTPUT
//123
//6
//5
*/

/*
#include <iostream>

class Something {
public:
	Something() { std::cout << "2"; }
};

class Base {
public:
	Base(int i) : _i{i} {std::cout  << "1"; }
	int getI() const { return _i;}
private:
	int _i;
};

class Derived : public Base {
public:
	Derived(int j) : _j(j),  Base(j) { std::cout << "3"; }
	int getJ() const { return _j;}
private:
	Something s;
	int _j;
};

int main() {
	Derived d(99);
	std::cout << std::endl;
	std::cout << d.getI() << std::endl;
	std::cout << d.getJ() << std::endl;
}
//OUTPUT
//123
//99
//99
*/

/*
#include <iostream>

class Something {
public:
	Something() { std::cout << "2"; }
};

class Base {
public:
	Base(int i) : _i{i} {std::cout  << "1"; }
	int getI() const { return _i;}
private:
	int _i;
};

class Derived : public Base {
public:
	Derived(int j) : _j(j),  Base(_j) { std::cout << "3"; }
	int getJ() const { return _j;}
private:
	Something s;
	int _j;
};

int main() {
	Derived d(99);
	std::cout << std::endl;
	std::cout << d.getI() << std::endl;
	std::cout << d.getJ() << std::endl;
}
//OUTPUT
//123
//0 //undefined behaviour
//99
*/

/*
#include <iostream>

class Something {
public:
	Something() { std::cout << "2"; }
};

class Base {
public:
	Base(int i) : _i{i} {std::cout  << "1"; }
	int getI() const { return _i;}
private:
	int _i;
};

class Derived : public Base {
public:
	Derived() : _j(4),  Base(_j) { std::cout << "3"; }
	int getJ() const { return _j;}
private:
	Something s;
	int _j;
};

int main() {
	Derived d;
	std::cout << std::endl;
	std::cout << d.getI() << std::endl;
	std::cout << d.getJ() << std::endl;
}
//OUTPUT:
//123
//0 //undefined behaviour
//4
*/

/*
#include <iostream>

class Something {
public:
        Something() { std::cout << "2"; }
        Something(int z) { std::cout << "2*"; }
private:
        int i;
};

class Base {
public:
        Base() {std::cout  << "1"; }
};

class Derived : public Base {
public:
        Derived() : s(4) { std::cout << "3"; }
private:
        Something s;
};

int main() {
        Derived d;
        std::cout << std::endl;
}
*/

/*
#include <iostream>

class Something {
public:
        Something() { std::cout << "2"; }
};

class Base {
public:
        Base() {std::cout  << "1"; }
};

class Derived : public Base {
public:
        Derived() { std::cout << "3"; }
private:
        Something s;
};

int main() {
        Derived d;
        std::cout << std::endl;
}
*/
