//std::bit_cast
/*
//1
#include <iostream>
#include <bit>

int main() {
	if (sizeof(int) == sizeof(float)) { 
		int source = 42;
		float target = std::bit_cast<float>(source);
        	std::cout << source << " " << target << std::endl;
	}
}
//The binary representation of the integer value 'source' is converted to its equivalent float representation using IEEE-32 format. The resulting float value is then displayed.
//00000000000000000000000000101010
//sign bit = 0 => sign = 1
//exponent = 0 => denormalized value
//fraction = 42, mantisa = fraction
//Exp = 1 - Bias = -126
//number = 0.00000000000000000101010 * 2^(-126) = 5.9e-44
//If you use reinterpret_cast you will get an error and if you use static_cast, the output will be 42 42 
*/

/*
//2
#include <iostream>
#include <bit>

int main() {
	float asFloat { 1.23f };
	auto asUint { std::bit_cast<unsigned int>(asFloat) };
	std::cout << asFloat << " " << asUint << std::endl;
	if (std::bit_cast<float>(asUint) == asFloat) { 
		std::cout << "Roundtrip success." << std::endl; 
	}
}
//00111111100111010111000010100100 = 1074191268
*/

/*
//3
#include <iostream>
#include <bit>

class A {
public:
        A() : x{1} {}
        void printState() { std::cout << "double x = " << x << std::endl; }
private:
	double x;
    
};

class B {
public:
        B() : y{2}, z{3} {}
        void printState() { std::cout << "int y = " << y << "   int z = " << z << std::endl; }
private:
        int y;
        int z;
};

int main() {
        A ob1;
        if (sizeof(A) == sizeof(B)) {
        	B ob2 = std::bit_cast<B>(ob1);
        	ob1.printState();
        	ob2.printState();
        }
}

//Output
//double x = 1
//int y = 0   int z = 1072693248

//0011111111110000000000000000000000000000000000000000000000000000
//y = 00000000000000000000000000000000 = 0
//z = 00111111111100000000000000000000 = 1072693248
*/
