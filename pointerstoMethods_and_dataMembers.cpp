#include <iostream>

class Point {
public:
    Point(int v) : m_v{v}, midpoint{0} {}
    int getDot() const { return m_v; }
    static void display() { std::cout << "-infinity  0  +infinity" << std::endl; }

public:
    inline static int unitLength = 1;
    int midpoint;

private:
    int m_v;
};

int main() {
    int (Point::*Fptr)() const = &Point::getDot;

    Point A(4);
    std::cout << (A.*Fptr)() << std::endl;

    Point* p = new Point(3);
    std::cout << (p->*Fptr)() << std::endl;


    void (*staticMFptr)() = &Point::display;
    staticMFptr();

    int* staticVPtr = &Point::unitLength;
    int Point::*nonStaticVPtr = &Point::midpoint;
    std::cout << *staticVPtr << A.*nonStaticVPtr << std::endl;
    
    //int Point::*privateNonStaticVPtr = &Point::m_v; //error
    
    return 0;
}

