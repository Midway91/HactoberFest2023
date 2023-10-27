#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random password
std::string GeneratePassword(int length) {
    const std::string charset =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    const int charsetLength = charset.length();
    std::string password;

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charsetLength;
        password += charset[randomIndex];
    }

    return password;
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int passwordLength;
    std::cout << "Enter the desired password length: ";
    std::cin >> passwordLength;

    if (passwordLength <= 0) {
        std::cout << "Invalid password length." << std::endl;
        return 1;
    }

    std::string password = GeneratePassword(passwordLength);

    std::cout << "Generated Password: " << password << std::endl;

    return 0;
}
