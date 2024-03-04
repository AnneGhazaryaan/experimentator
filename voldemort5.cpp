#include <iostream>

class Animal {
private:
    int a;
public:
    void performAnimalAction() {
        std::cout << "Animal Action" << std::endl;
    }
};

class Dog : virtual public Animal {
private:
    int c;
public:
    void bark() {
        std::cout << "Bark!" << std::endl;
    }
};

class Bird : virtual public Animal {
private:
    int z;
public:
    void chirp() {
        std::cout << "Chirp!" << std::endl;
    }
};

class DogBird : public Dog, public Bird {
private:
    int m;
public:
    void performDogBirdAction() {
        std::cout << "DogBird Action" << std::endl;
    }
};

int main() {
    DogBird ob;
    ob.performAnimalAction();
    ob.bark();
    ob.chirp();
    ob.performDogBirdAction();

    return 0;
}

