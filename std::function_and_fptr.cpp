#include <iostream>
#include <functional>

using fptr =  void (*)(int);

void printArray(int arr[], int size, std::function<void(int)> func) {
    for (int i = 0; i < size; ++i) {
        func(arr[i]);
    }
}

/*
//this won't work
void printArray(int arr[], int size, fptr func) {
    for (int i = 0; i < size; ++i) {
        func(arr[i]);
    }
}
*/
void printSquare(int num) {
    std::cout << num * num << " ";
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};

    fptr y = printSquare;
    printArray(myArray, 5, y);
    
    std::cout << std::endl;
    
    std::function<void(int)> x = printSquare;
    printArray(myArray, 5, x);
    
    std::cout << std::endl;

    return 0;
}

