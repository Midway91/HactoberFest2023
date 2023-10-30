#include <iostream>
#include <string>

int main() {
    std::string bigString;
    std::string subString;

    // Input the big string
    std::cout << "Enter the big string: ";
    std::cin >> bigString;

    // Input the substring
    std::cout << "Enter the substring to search for: ";
    std::cin >> subString;

    // Use the find() method to search for the substring in the big string
    size_t found = bigString.find(subString);

    if (found != std::string::npos) {
        std::cout << "Substring found at position " << found << std::endl;
    } else {
        std::cout << "Substring not found in the big string." << std::endl;
    }

    return 0;
}
