#include <iostream>
#include <string>

class Book {
public:
	virtual ~Book() = default;
	virtual std::string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120; }
};

class Paperback : public Book {
public:
	std::string getDescription() const override {
		return "Paperback " + Book::getDescription();
	}
};

class Romance : public Paperback {
public:
	std::string getDescription() const override {
		return "Romance " + Paperback::getDescription();
	}
	int getHeight() const override { return Paperback::getHeight() / 2; }
/*
	The Book base class has two virtual methods: getDescription() and getHeight(). 
	All derived classes override getDescription(), but only the Romance class overrides getHeight() by calling
	getHeight() on its parent class (Paperback) and dividing the result by two. 
	Paperback does not override getHeight(), but C++ walks up the class hierarchy to find a class that implements
	get­Height(). In this example, Paperback::getHeight() resolves to Book::getHeight().
	//You can also write as follows:
	//int getHeight() const override { return Book::getHeight() / 2; }
	//It's the same IN THIS CASE, but I dont recommend, because price of Romance should based on price of Paperback not on Book.
	//So if you write Book::getHeight() and someday someone override getHeight() in Paperback, you will have a bug

*/
};

class Technical : public Book {
public:
	std::string getDescription() const override {
		return "Technical " + Book::getDescription();
	}
};

int main() {
	Romance novel;
	Book book;
	std::cout << novel.getDescription() << std::endl; // Outputs "Romance Paperback Book"
	std::cout << book.getDescription() << std::endl; // Outputs "Book"
	std::cout << novel.getHeight() << std::endl; // Outputs "60"
	std::cout << book.getHeight() << std::endl; // Outputs "120"
}
