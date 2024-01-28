#include <iostream>

class Point {
public:
//    explicit Point(int initialX) : x(initialX) {}
    Point(int initialX) : x(initialX) {}
    int getX() const { return x; }
    Point operator+(const Point& other) const { return Point(x + other.x); }

private:
    int x;
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.getX();
    return os;
}

int main() {
    Point p1(5);
    Point p2(10);
    Point p3 = p1 + p2;
    Point p4 = p1 + 1;
    Point p5 = p1 + 1.5;
    Point p6 = p1 + 'a';
    Point p7 = p1 + 2.7f;
    bool b = true;
    Point p8 = p1 + b;
    std::cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " <<p6 << " " << p7 << " " << p8 << std::endl;

    Point pp1 = p1 + 4; //It is ok, until O have converting ctor
    //Point pp2 = 4 + p1; //Even if I have converting ctor, this woudn't work, It can work only if I have non_member function wich get 2 Points or non_member function which get int, and Point
    // see the example below

    return 0;
}


/*
#include <iostream>

class Point {
public:
//    explicit Point(int initialX) : x(initialX) {}
    Point(int initialX) : x(initialX) {}
    int getX() const { return x; }
    Point operator+(const Point& other) const { return Point(x + other.x); }

private:
    int x;
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.getX();
    return os;
}


//first option
Point operator+(const Point& lhs, const Point& rhs) {
    return Point{lhs.getX() + rhs.getX()};
}



//second option if you wonna define your ctor as "explicit"
//Point operator+(int lhs, const Point& rhs) {
//    return Point{lhs + rhs.getX()};
//}

int main() {
    Point p1(5);
    Point p2(10);
    Point pp2 = 4 + p1;

    std::cout << pp2 << std::endl; 
    return 0;
}
*/























