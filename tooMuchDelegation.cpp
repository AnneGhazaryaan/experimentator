#include <iostream>
#include <string>

class W {
public:
	W(const std::string s) : W(t,0,0)  {std::cout << "HI";}
	W(const std::string s,int a, int b) : W(s) { std::cout << "bye";}
private:
	std::string t;
	int w;
	int h;

};
int main() {
	std::string st = "ad";
	W e(st);
}
