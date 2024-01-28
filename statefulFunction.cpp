#include <iostream>

class Adder {
public:
	Adder() : _sum{} {}
	void operator()(int x) {
		_sum += x;
	}
	int getSum() const { return _sum; }
private:
	int _sum;
};

class Array {
public:
	Array(int size) : m_size{size}, m_ptr{new int[size]} {}
	const int& operator[](int index) const { return m_ptr[index];} 
  //int operator[](int index) const { return m_ptr[index];} //From constant methods you can also return the object itself. This is especially useful when you are dealing with built-in types
	int& operator[](int index) { return m_ptr[index];}
	void traverse(Adder& a) {
		for (int i = 0; i < m_size; ++i) {
			a(m_ptr[i]);
		}
	}
private:
	int m_size;
	int* m_ptr;
};


int main() {
	Array arr(2);
	arr[0] = 5;
	arr[1] = 7;
	Adder callable_object;
	arr.traverse(callable_object);
	std::cout << callable_object.getSum() << std::endl;

	return 0;
}
