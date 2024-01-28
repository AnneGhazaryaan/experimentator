/*#include <iostream>

class Point {
private:
    int x;

public:
    int getX() const {
	display();
        return x;
    }
    void setX(int newX) {
        x = newX;
    }

    void display() {
        std::cout << "hello" << std::endl;
    }


};

int main() {
    Point p;
    p.setX(9);
    std::cout << p.getX() << std::endl;
    return 0;
}
*/

#include <iostream>

void display() {
    std::cout << "hello" << std::endl;
}

class Point {
private:
    int x;

public:
    int getX() const {
        display();
        return x;
    }
    void setX(int newX) {
        x = newX;
    }
};

int main() {
    Point p;
    p.setX(9);
    std::cout << p.getX() << std::endl;
    return 0;
}

