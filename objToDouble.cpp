/*
"I can overload the operator for casting my object into, for example, double. I can do this in two ways. 
In the first variant, the conversion will be made implicitly after I provide overloading. 
In the second variant, if I write my overloading with the explicit keyword, until the user doesn't try to make it explicit, it will give an error."
*/

#include <iostream>

class A {
public:
	operator double() {return 3.14;}
};

int main() {
        A ob;
        double d = ob;
        std::cout << d << std::endl;
        return 0;
}

//explicit cast
/*
#include <iostream>

class A {
public:
	explicit operator double() {return 3.14;}
};

int main() {
	A ob;
	double d = static_cast<double>(ob);
	//double d = ob; //error!
	std::cout << d << std::endl;
	return 0;
}
*/

//Not much related to the above.
//Naturally this doesn't work.
/*
#include <iostream>

class A {
public:
	double d{3.14};
};

int main() {
	A ob;
	double d = static_cast<double>(ob);
	std::cout << d << std::endl;
	return 0;
}
*/
