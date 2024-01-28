/*
#include <iostream>

enum M{A};

int operator+(M m, int i) {
        return static_cast<int>(m) + i - 1;
        //return static_cast<int>(m) + i - 1;// Segmentation fault
}

int main() {
        M m;
        std::cout << m + 4 << std::endl;
        return 0;
}
*/
//In the first example, you should use static_cast during the return value evaluation to call operator+(int, int). If you don't use the cast, you will get a segmentation fault because it will call itself.
//In the second example, you don't need a cast because the compiler will do it on its own (because there is no specific function exactly for the enum).
#include <iostream>

enum M{A};

int foo(M m, int i) {
	return m + i - 1;
}
int main() {
        M m;
        std::cout << foo(m,4) << std::endl;
        return 0;
}
