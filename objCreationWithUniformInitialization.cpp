#include <iostream>
#include <string>

class X {
public:
	X(int x, int y, std::string s) : _x{x}, _y{y}, _s{s} {}
	void print() {
		std::cout << _x << " " << _y << " " << _s << std::endl;
	}
private:
	int _x;
	int _y;
	std::string _s;
};

int main() {
	X ob{2,3, "Hallo, Vlodik!"};
	ob.print();
}
