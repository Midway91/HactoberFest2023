#include <iostream>
#include <map>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::map; using std::copy;

template<typename Map>
void PrintMap(Map& m)
{
    cout << "[ ";
    for (auto &item : m) {
        cout << item.first << ":" << item.second << " ";
    }
    cout << "]\n";
}

int main() {
    map<int, string> map1 = {{1, "Apple",},
                                {2, "Banana",},
                                {3, "Mango",},
                                {4, "Raspberry",},
                                {5, "Blackberry",},
                                {6, "Cocoa",}};

    cout << "map1 - ";
    PrintMap(map1);
    cout << endl;

    return EXIT_SUCCESS;
}