#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    if (num & 1) {
        std::cout << num << " is odd." << std::endl;
    } else {
        std::cout << num << " is even." << std::endl;
    }
    
    return 0;
}
