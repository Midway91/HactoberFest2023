#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generatePassword(int length, bool useLower, bool useUpper, bool useNumbers, bool useSpecial) {
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numbers = "0123456789";
    const string specialChars = "!@#$%^&*()_-+=<>?";

    string characterSet = "";

    if (useLower) characterSet += lowercase;
    if (useUpper) characterSet += uppercase;
    if (useNumbers) characterSet += numbers;
    if (useSpecial) characterSet += specialChars;

    string password;
    int charSetSize = characterSet.size();

    srand(time(0));
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charSetSize;
        password += characterSet[randomIndex];
    }

    return password;
}

int main() {

    int length;
    bool useLower, useUpper, useNumbers, useSpecial;

    cout << "Welcome to the Cool Password Generator" << endl;
    cout << "Password Length: ";
    cin >> length;

    cout << "Include lowercase letters? (1/0): ";
    cin >> useLower;

    cout << "Include uppercase letters? (1/0): ";
    cin >> useUpper;

    cout << "Include numbers? (1/0): ";
    cin >> useNumbers;

    cout << "Include special characters? (1/0): ";
    cin >> useSpecial;

    if (useLower || useUpper || useNumbers || useSpecial) {
        string password = generatePassword(length, useLower, useUpper, useNumbers, useSpecial);
        cout << "Your generated password is: " << password << endl;
    } else {
        cout << "At least one character set must be included in the password." << endl;
    }

    return 0;
}
