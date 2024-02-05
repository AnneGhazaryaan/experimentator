/*
//This won't work
#include <iostream>
#include <vector>
#include <cstddef>


void findMatches(std::vector<int> v1, std::vector<int> v2,
         bool(*f1)(int,int), void(*f2)(std::size_t,int,int)) {
        for (std::size_t i{0}; i < v1.size(); ++i) {
                if(f1(v1[i],v2[i])) {
                        f2(i,v1[i],v2[i]);
                }
        }
}

void printMatches(std::size_t s, int v1, int v2) {
	std::cout << s << " " << v1 << " " << v2 << " ";
}

class a {
public:
	a(int v) : _v{v} {}
	bool operator()(int x, int y) const {
		return x>_v && y >_v;
	}
private:
	int _v;
};

int main() {
	std::vector v1{2,500,6,9,10,101,1};
	std::vector v2{4,4,2,9,0,300,1};
	findMatches(v1,v2,a(100),printMatches);
	return 0;
}


error: cannot convert ‘a’ to ‘bool (*)(int, int)’
   32 |         findMatches(v1,v2,a(100),printMatches);
      |                           ^~~~~~
      |                           |
      |                           a
functionObject_std::function_fptr.cpp:7:16: note:   initializing argument 3 of ‘void findMatches(std::vector<int>, std::vector<int>, bool (*)(int, int), void (*)(std::size_t, int, int))’
    7 |          bool(*f1)(int,int), void(*f2)(std::size_t,int,int)) {
      |          ~~~~~~^~~~~~~~~~~~

*/

/*
//This will work
#include <iostream>
#include <vector>
#include <cstddef>

template <typename t1, typename t2>
void findMatches(std::vector<int> v1, std::vector<int> v2, t1 f1, t2 f2) {
        for (std::size_t i{0}; i < v1.size(); ++i) {
                if(f1(v1[i],v2[i])) {
                        f2(i,v1[i],v2[i]);
                }
        }
}

void printMatches(std::size_t s, int v1, int v2) {
        std::cout << s << " " << v1 << " " << v2 << " ";
}

class a {
public:
        a(int v) : _v{v} {}
        bool operator()(int x, int y) const {
                return x>_v && y >_v;
        }
private:
        int _v;
};

int main() {
        std::vector v1{2,500,6,9,10,101,1};
        std::vector v2{4,4,2,9,0,300,1};
        findMatches(v1,v2,a(100),printMatches);
	std::cout << std::endl;
        return 0;
}
*/

/*
//This will work
#include <iostream>
#include <vector>
#include <cstddef>
#include <functional>

void findMatches(std::vector<int> v1, std::vector<int> v2,
                 const std::function<bool(int, int)>& f1,
                 const std::function<void(std::size_t, int, int)>& f2) {
        for (std::size_t i{0}; i < v1.size(); ++i) {
            if (f1(v1[i], v2[i])) {
                f2(i, v1[i], v2[i]);
            }
        }
}

void printMatches(std::size_t s, int v1, int v2) {
        std::cout << s << " " << v1 << " " << v2 << " ";
}

class a {
public:
        a(int v) : _v{v} {}
        bool operator()(int x, int y) const {
            return x > _v && y > _v;
        }

private:
        int _v;
};

int main() {
        std::vector<int> v1{2, 500, 6, 9, 10, 101, 1};
        std::vector<int> v2{4, 4, 2, 9, 0, 300, 1};

        // Using std::function to wrap the callable objects
        std::function<bool(int, int)> compareFunction = a(100);
        std::function<void(std::size_t, int, int)> printFunction = printMatches;
 
        findMatches(v1, v2, compareFunction, printFunction);
        std::cout << std::endl;

    return 0;
}
*/
