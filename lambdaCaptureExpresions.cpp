#include <iostream>

int main() {
    int h = 9;
    auto l = [c = 'v',h = 4](int x) { 
        std::cout << c << std::endl;
        return x * h;
    };

/*
//ERROR
    auto l = [char c = 'v',h = 4](int x) { 
        std::cout << c << std::endl;
        return x * h;
    };
*/
/*
//ERROR
    auto l = [c = 'v',h = 4](int x) {
	c = 'a'; 
        std::cout << c << std::endl;
        return x * h;
    };
*/
/*
//ERROR
    auto l = [c = 'v',&h = 4](int x) { 
        std::cout << c << std::endl;
        return x * h;
    };
*/
/*
//ERROR
    auto l = [c = 'v',h = 4](int x) {
	++h; 
        std::cout << c << std::endl;
        return x * h;
    };
*/
    std::cout << l(2) << std::endl;
    std::cout << h << std::endl;
    return 0;
}

