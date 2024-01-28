#include <iostream>

int main() {
	const char* s1 = "etimi chor";
	const char* s2 = "etimi chor";
	std::cout << (void*)s1 << std::endl;
	std::cout << (void*)s2 << std::endl;
	return 0;
}
