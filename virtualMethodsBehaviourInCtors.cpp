#include <iostream>

class Base {
public:
        Base() : _b{0} {
                std::cout << "Base ctor" << std::endl;
                print();
        }
        virtual void print() { std::cout << "Hi1" << std::endl;}
private:
        int _b;
};

class Derived : public Base {
public:
        Derived() : _d{0} {
                std::cout << "Derived ctor" << std::endl;
                print();
        }
        void print() override { std::cout << "Hi2" << std::endl;}
private:
        int _d;
};

int main() {
        Derived obj;
}
/*
#include <iostream>

class Base {
public:
	Base() : _b{0} { 
		std::cout << "Base ctor" << std::endl;
		print();
	}
	virtual void print() { std::cout << "Hi1" << std::endl;}
private:
	int _b;
};

class Derived : public Base { 
public:
	Derived() : _d{0} { 
		std::cout << "Derived ctor" << std::endl;
	}
	void print() override { std::cout << "Hi2" << std::endl;}
private:
	int _d;
};

int main() {
	Derived obj;
}
*/
