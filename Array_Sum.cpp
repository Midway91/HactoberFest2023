#include <iostream>

int main() {
    int n;
    
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Please enter a valid number of elements." << std::endl;
        return 1;
    }
    
    int arr[n];
    
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    std::cout << "Sum of the elements in the array is: " << sum << std::endl;
    
    return 0;
}
