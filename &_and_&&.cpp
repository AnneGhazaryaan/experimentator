#include <iostream>
#include <string>

class Text {
public:
	Text(std::string m) : _m{std::move(m)} {} //this is the best tactic if copying is inevitable
	const std::string& getText() const & {
		std::cout << "&" << std::endl;
		return _m;
	}
	std::string&& getText() && {
		std::cout << "&&" << std::endl;
		return std::move(_m);
	}
public:
	std::string _m;
};

int main() {
	Text{"hi"}.getText();

	Text ob("hi");
	const std::string& r = ob.getText();
	ob._m = "bye";
	std::cout << r << std::endl;
	
	std::string str = ob.getText();
	std::cout << str << std::endl;
	
	str += "!";
	std::cout << str << std::endl;
	std::cout << r << std::endl;

	return 0;
}
