#include <iostream>
#include <memory>

class Mlass {
public:
	void sm() { std::cout << "sm()" << std::endl;}
	/*virtual*/ ~Mlass() { std::cout << "dtor1()" << std::endl;};
private:
	std::unique_ptr<int> p;
};

class MlassVazvrasheniye : public Mlass {
public:
	~MlassVazvrasheniye() { std::cout << "dtor2()" << std::endl;};
private:
	int count;
};

int main() { 
	std::unique_ptr<Mlass> ptr = std::make_unique<MlassVazvrasheniye>();
	Mlass* ptr2 = new MlassVazvrasheniye();
	delete ptr2;
}
/*
//OUTPUT WITH VIRTAUL
dtor2()
dtor1()
dtor2()
dtor1()

//OUTPUT WITHOUT VIRTAUL //please note that this behavior is not defined by the standard
dtor1()
dtor1()

*/
