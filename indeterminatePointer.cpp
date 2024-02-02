#include <iostream>

int main() {
	int* ptr;
	*ptr = 5;
	std::cout << ptr << " " << *ptr << std::endl;
	return 0;
}


/*
The pointer ptr will have an indeterminate value, meaning it will contain garbage or an unpredictable(непредсказуемое) value. It is important to note that the pointer is not automatically set to nullptr or any other specific value. You should always initialize pointers before using them to avoid undefined behavior.

I declare a pointer ptr but do not initialize it, so it contains an indeterminate value. Then, I try to dereference it using the line *ptr = 5;. Dereferencing an uninitialized pointer, or a pointer pointing to nullptr, leads to undefined behavior and in this case, it results in a segmentation fault.
*/
