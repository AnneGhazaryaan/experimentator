/*
//if you do specify a copy constructor in the derived class, you need to explicitly chain to the parent copy constructor, as shown in the following code. If you do not do this, the default constructor (not the copy constructor!) will be used for the parent portion of the object.
#include <iostream>

class Base {
public:
	Base() : data(1) {}
        Base(const Base& other) : data(other.data) {}
        Base& operator=(const Base& other) {
                if (this != &other) {
			data = other.data;
		}
                return *this;
        }
	virtual void setData(int d) { data = d; }
        virtual int getData() const { return data;}
private:
        int data;
};

class Derived : public Base {
public:
	Derived() : data2(2) {}
        Derived(const Derived& other) : data2(other.data2) {}
        Derived& operator=(const Derived& other) {
                if (this != &other) {
			data2 = other.data2;
		}
                return *this;
        }
	void setData(int d) override { data2 = d; }
        int getData() const override { return data2;}
private:
        int data2;
};

int main() {
	Derived ob;
	ob.Base::setData(5);
	Derived ob2 = ob;
	std::cout << ob.getData() << " " << ob.Base::getData() << std::endl;
	std::cout << ob2.getData() << " " << ob2.Base::getData() << std::endl;
        return 0;
}

//OUTPUT
//2 5
//2 1
*/

/*
#include <iostream>

class Base {
public:
	Base() : data(1) {}
        Base(const Base& other) : data(other.data) {}
        Base& operator=(const Base& other) {
                if (this == &other) {
			return *this;
		}
                data = other.data;
		return *this;
        }
	virtual void setData(int d) { data = d; }
        virtual int getData() const { return data;}
private:
        int data;
};

class Derived : public Base {
public:
	Derived() : data2(2) {}
        Derived(const Derived& other) : Base{other}, data2(other.data2) {}
        Derived& operator=(const Derived& other) {
                if (this == &other) {
			return *this;
		}
		Base::operator=(other);
                data2 = other.data2;
		return *this;
        }
	void setData(int d) override { data2 = d; }
        int getData() const override { return data2;}
private:
        int data2;
};

int main() {
	Derived ob;
	ob.Base::setData(5);
	Derived ob2 = ob;
	std::cout << ob.getData() << " " << ob.Base::getData() << std::endl;
	std::cout << ob2.getData() << " " << ob2.Base::getData() << std::endl;
        return 0;
}

//OUTPUT
//2 5
//2 5
*/

/*
#include <iostream>

class Base {
public:
	Base() : data(1) {}
        Base(const Base& other) : data(other.data) {}
        Base& operator=(const Base& other) {
                if (this == &other) {
			return *this;
		}
                data = other.data;
		return *this;
        }
	virtual void setData(int d) { data = d; }
        virtual int getData() const { return data;}
private:
        int data;
};

class Derived : public Base {
public:
	Derived() : data2(2) {}
        Derived(const Derived& other) : Base{other}, data2(other.data2) {}
        Derived& operator=(const Derived& other) {
                if (this == &other) {
			return *this;
		}
		Base::operator=(other);
                data2 = other.data2;
		return *this;
        }
	void setData(int d) override { data2 = d; }
        int getData() const override { return data2;}
private:
        int data2;
};

void copyAndPrint(const Base& obj) {
	Base copiedObj = obj;
	std::cout << copiedObj.getData() << std::endl;
}

int main() {
	Derived ob;
	ob.Base::setData(5);
	Derived ob2 = ob;
	std::cout << ob.getData() << " " << ob.Base::getData() << std::endl;
	std::cout << ob2.getData() << " " << ob2.Base::getData() << std::endl;
	std::cout << std::endl;
	copyAndPrint(ob);
	
        return 0;
}

//This causes slicing of the derived object, so it's better to use the polymorphic clone() idiom

//OUTPUT
//2 5
//2 5
//5
*/

#include <iostream>

class Base {
public:
    Base() : data(1) {}
    Base(const Base& other) : data(other.data) {}
    virtual ~Base() {}

    virtual Base* clone() const {
        return new Base(*this);
    }

    Base& operator=(const Base& other) {
        if (this == &other) {
            return *this;
        }
        data = other.data;
        return *this;
    }

    virtual void setData(int d) { data = d; }
    virtual int getData() const { return data; }

private:
    int data;
};

class Derived : public Base {
public:
    Derived() : data2(2) {}
    Derived(const Derived& other) : Base{other}, data2(other.data2) {}

    Base* clone() const override {
        return new Derived(*this);
    }

    Derived& operator=(const Derived& other) {
        if (this == &other) {
            return *this;
        }
        Base::operator=(other);
        data2 = other.data2;
        return *this;
    }

    void setData(int d) override { data2 = d; }
    int getData() const override { return data2; }

private:
    int data2;
};

void copyAndPrint(const Base& obj) {
    Base* copiedObj = obj.clone();
    std::cout << copiedObj->getData() << std::endl;
    delete copiedObj;  
}

int main() {
    Derived ob;
    ob.Base::setData(5);
    Derived ob2 = ob;
    std::cout << ob.getData() << " " << ob.Base::getData() << std::endl;
    std::cout << ob2.getData() << " " << ob2.Base::getData() << std::endl;
    std::cout << std::endl;
    copyAndPrint(ob);

    return 0;
}

//OUTPUT
//2 5
//2 5
//2















