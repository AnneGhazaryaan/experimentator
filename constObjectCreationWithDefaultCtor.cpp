#include <iostream>

class A {
public:
	A() : _x{}, _y{} {}
private:
	int _x;
	int _y;
};

int main() {
	const A ob;
	return 0;
}

//The above example is correct, but if I don't define default ctor myself I’ll get an error
/*
#include <iostream>

class A {
private:
        int _x;
        int _y;
};

int main() {
        const A ob;
        return 0;
}

*/

//This also gives an error
/*
/#include <iostream>

class A {
public:
        A() = default
private:
        int _x;
        int _y;
};

int main() {
        const A ob;
        return 0;
}
*/
