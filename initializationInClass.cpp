//I can do it since c++11
//-std=c++98 i get an error
#include <iostream>

class X {
public:
	void print() {
		std::cout << _x << "  " << _y << std::endl;
	}
private:
	int _x = 3;
	int _y = 4;
};

int main() {
	X ob;
	ob.print();
	return 0;
}
