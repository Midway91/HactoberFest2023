#include <iostream>

int main() {
    int a = 5, b = 10;

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}
