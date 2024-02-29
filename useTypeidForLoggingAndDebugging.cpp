#include <iostream>
#include <typeinfo>

class Loggable {
public:
    virtual ~Loggable() = default;
    virtual std::string getLogMessage() const = 0;
};

class Foo : public Loggable {
public:
    std::string getLogMessage() const override { return "Greetings from Foo."; }
};

class Bar : public Loggable {
public:
    std::string getLogMessage() const override { return "Greetings from Bar."; }
};

void logObject(const Loggable& loggableObject) {
    std::cout << typeid(loggableObject).name() << ": ";
    std::cout << loggableObject.getLogMessage() << std::endl;
}

int main() {
    Foo fooObj;
    Bar barObj;

    logObject(fooObj);
    logObject(barObj);

    return 0;
}

