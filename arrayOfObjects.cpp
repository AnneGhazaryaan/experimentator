#include <iostream>

class Widget {
public:
        Widget(int x, int y) : _x{x}, _y{y} {}
        int getX() const {return _x;}
        int getY() const {return _y;}
private:
        int _x;
        int _y;
};

int main() {
	const int size = 3;
        Widget arr[size] {Widget(1,2), Widget(3,4), Widget(5,6) }; //Ok!
        //Widget arr[size] {{1,2}, {3,4}, {5,6} }; //Ok!
        //Widget arr[size] {(1,2), (3,4), (5,6) }; //Error!
        for (int i = 0; i < size; ++i) {
                std::cout << arr[i].getX() << " " << arr[i].getY() << std::endl;
        }
        return 0;
}


/*
#include <iostream>

class Widget {
public:
        Widget(int x) : _x{x} {}
        int getX() const {return _x;}
private:
        int _x;
};

int main() {
        const int size = 3;
        Widget arr[size] {1,2,3}; //Ok!
        //Widget arr[size] {Widget(1),Widget(2),Widget(3)}; //Ok!
        for (int i = 0; i < size; ++i) {
                 std::cout << arr[i].getX() << std::endl;
        }
        return 0;
}
*/
