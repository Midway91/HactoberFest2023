#include <iostream>

int main()
{
    std::string name;
    std::cout<<"Enter your name\n";
    getline(std::cin , name);
    std::cout<<"Welcome Mr. "<<name;

    return 0;
}