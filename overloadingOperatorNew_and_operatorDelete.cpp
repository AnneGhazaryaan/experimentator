//Note that nothrow is actually a variable of type nothrow_t.
//These implementations of operator new and operator delete are obviously trivial and not particularly useful. They are intended only to give me an idea of the syntax in case I ever want to implement nontrivial versions of them.

#include <iostream>

class MemoryDemo {
public:
    virtual ~MemoryDemo() = default;

    void* operator new(size_t size);
    void operator delete(void* ptr) noexcept;

    void* operator new[](size_t size);
    void operator delete[](void* ptr) noexcept;

    void* operator new(size_t size, const std::nothrow_t&) noexcept;
    void operator delete(void* ptr, const std::nothrow_t&) noexcept;

    void* operator new[](size_t size, const std::nothrow_t&) noexcept;
    void operator delete[](void* ptr, const std::nothrow_t&) noexcept;
};

void* MemoryDemo::operator new(size_t size) {
    std::cout << "operator new" << std::endl;
    return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr) noexcept {
    std::cout << "operator delete" << std::endl;
    ::operator delete(ptr);
}

void* MemoryDemo::operator new[](size_t size) {
    std::cout << "operator new[]" << std::endl;
    return ::operator new[](size);
}

void MemoryDemo::operator delete[](void* ptr) noexcept {
    std::cout << "operator delete[]" << std::endl;
    ::operator delete[](ptr);
}

void* MemoryDemo::operator new(size_t size, const std::nothrow_t&) noexcept {
    std::cout << "operator new nothrow" << std::endl;
    return ::operator new(size, std::nothrow);
}

void MemoryDemo::operator delete(void* ptr, const std::nothrow_t&) noexcept {
    std::cout << "operator delete nothrow" << std::endl;
    ::operator delete(ptr, std::nothrow);
}

void* MemoryDemo::operator new[](size_t size, const std::nothrow_t&) noexcept {
    std::cout << "operator new[] nothrow" << std::endl;
    return ::operator new[](size, std::nothrow);
}

void MemoryDemo::operator delete[](void* ptr, const std::nothrow_t&) noexcept {
    std::cout << "operator delete[] nothrow" << std::endl;
    ::operator delete[](ptr, std::nothrow);
}

int main() {
    MemoryDemo* mem = new MemoryDemo{};
    delete mem;

    mem = new MemoryDemo[10];
    delete[] mem;

    mem = new (std::nothrow) MemoryDemo{};
    delete mem;

    mem = new (std::nothrow) MemoryDemo[10];
    delete[] mem;

    return 0;
}

