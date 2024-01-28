/*
#include <iostream>

int main() {
	int x{};
	int y{};
	++x = 4; //ok
//	y++ = 7; //not ok
	std::cout << x << std::endl;
	return 0;
}
*/

#include <iostream>

class Cell {
public:
    Cell(int initialValue = 0) : value(initialValue) {}

    int getValue() const { return value; }

    Cell& operator++() {
        ++value;
        return *this;
    }
    sa karox es naev aranc const veradarznel, voch mi xndir chka, bayc const-uv aveli mote built in typerin, vorovhetev cell++99-@ error kta
    const Cell operator++(int) {
        Cell temp(*this);
        ++value;
        return temp;
    }
private:
    int value;
};

int main() {
    Cell cell(5);

    ++cell;
    std::cout << "After prefix increment: " << cell.getValue() << std::endl;

    Cell anotherCell = cell++;
    std::cout << "After postfix increment: " << cell.getValue() << std::endl;
    std::cout << "Value before postfix increment: " << anotherCell.getValue() << std::endl;

    ++cell = 9;
    std::cout << cell.getValue() << std::endl;

    cell++ = 99;
    std::cout << cell.getValue() << std::endl;

    return 0;
}
