//const_cast
/*
//1
//const_cast is the only cast of the five that is allowed to cast away const-ness.
#include <iostream>
#include <bit>

int main() {
	const int constantNumber = 10;
        int& nonConstRef = const_cast<int&>(constantNumber);
        //int& nonConstRef = static_cast<int&>(constantNumber);//error
        //int& nonConstRef = reinterpret_cast<int&>(constantNumber);//error
        //int& nonConstRef = std::bit_cast<int&>(constantNumber);//error

	nonConstRef = 20;
	std::cout << "Modified value: " << constantNumber << std::endl;
}
*/

/*
//2
//The Standard Library provides a helper method called std::as_const(), defined in <utility>, which returns a reference-to-const version of its reference parameter. 
//Basically, as_const(obj) is equivalent to const_cast<const T&>(obj), where T is the type of obj. 
//Using as_const() results in shorter and more readable code compared to using const_cast().
#include <iostream>
#include <utility>

int main() {
    int nonConstVariable = 42;
    const int& constReference = std::as_const(nonConstVariable);

    // Attempting to modify the const reference will result in a compilation error
    // constReference = 55; // This line will not compile

    std::cout << "Original value: " << nonConstVariable << std::endl;
}
*/
