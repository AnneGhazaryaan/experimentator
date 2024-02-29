/*
#include <iostream>
#include <string>

class Base {
public:
	virtual ~Base() = default;
	virtual void set(std::string value) = 0;
	virtual std::string get() const = 0;
};

class D2;

class D1 : public Base {
public:
	D1() = default;
	D1(const D2& siblingObj);
public:
	void set(std::string value) override { _value = value; }
	std::string get() const override { return _value; }
private:
	std::string _value;
};

class D2 : public Base {
public:
	D2() = default;
	D2(const D1& siblingObj) : _value{stringToInt(siblingObj.get())} {}
public:
	virtual void set(int value) { _value = value; }
        void set(std::string value) override { _value = stringToInt(value); }
        std::string get() const override { return intToString(_value); }
	
protected:
	static std::string intToString(int value) { return std::to_string(value); }
	static int stringToInt(std::string value) { return std::stoi(value); }
private:
	int _value;
};

D1::D1(const D2& siblingObj) : _value{siblingObj.get()} {}

int main() {
	D1 ob;
	ob.set("4");
	D2 obj(ob);
	std::cout << obj.get() << std::endl;
}
*/
//With cast operator
#include <iostream>
#include <string>

class Base {
public:
        virtual ~Base() = default;
        virtual void set(std::string value) = 0;
        virtual std::string get() const = 0;
};

class D2;

class D1 : public Base {
public:
        D1() = default;
        D1(const D2& siblingObj);
public:
        void set(std::string value) override { _value = value; }
        std::string get() const override { return _value; }
	explicit operator D2();
private:
        std::string _value;
};

class D2 : public Base {
public:
        D2() = default;
        D2(const D1& siblingObj) : _value{stringToInt(siblingObj.get())} {}
public:
        virtual void set(int value) { _value = value; }
        void set(std::string value) override { _value = stringToInt(value); }
        std::string get() const override { return intToString(_value); }
	explicit operator D1() {
 	        D1 d1Object;
        	d1Object.set(intToString(_value));
		return d1Object;
	}

protected:
        static std::string intToString(int value) { return std::to_string(value); }
        static int stringToInt(std::string value) { return std::stoi(value); }
private:
        int _value;
};

D1::D1(const D2& siblingObj) : _value{siblingObj.get()} {}
D1::operator D2() {
        D2 d2Object;
        d2Object.set(std::stoi(_value));
        return d2Object;
}

int main() {
        D1 obD1;
        obD1.set("4");
        D2 obD2 = static_cast<D2>(obD1);
        std::cout << "D2 object value: " << obD2.get() << std::endl;

        D2 obD2_2;
        obD2_2.set(8);
        D1 obD1_2 = static_cast<D1>(obD2_2);
        std::cout << "D1 object value: " << obD1_2.get() << std::endl;

        return 0;
}
