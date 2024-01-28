#include <iostream>

class m {
public:
    void set(int v) {
        m::v = v; //wooooooooooooooooooooooooow!
    }
    int get() const {
        return v;
    }
private:
    int v;
};

int main()
{
    m ob;
    ob.set(5);
    std::cout << ob.get() << std::endl;
}
