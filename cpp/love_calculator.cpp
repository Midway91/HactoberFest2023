#include <iostream>
#include <string>

using namespace std;

int calculateLovePercentage(const string& name1, const string& name2) {
    int lovePercentage = 0;

    for (char c : name1) {
        for (char d : name2) {
            if (tolower(c) == tolower(d))
                lovePercentage += 10;
        }
    }

    return lovePercentage;
}

int main() {
    string name1, name2;

    cout << "Enter the first name: ";
    getline(cin, name1);

    cout << "Enter the second name: ";
    getline(cin, name2);

    int lovePercentage = calculateLovePercentage(name1, name2);

    cout << "\nLove Percentage: " << lovePercentage << "%" << endl;

    return 0;
}
