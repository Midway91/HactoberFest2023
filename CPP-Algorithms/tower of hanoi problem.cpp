#include <iostream>

// Function to solve the Tower of Hanoi problem
// Parameters:
// - n: Number of disks
// - source: Source rod
// - auxiliary: Auxiliary rod
// - target: Target rod
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        // If there's only one disk, move it from the source to the target
        std::cout << "Move disk 1 from " << source << " to " << target << std::endl;
        return;
    }

    // Move n-1 disks from the source to the auxiliary using the target as an auxiliary
    towerOfHanoi(n - 1, source, target, auxiliary);

    // Move the largest disk from the source to the target
    std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;

    // Move the n-1 disks from the auxiliary to the target using the source as an auxiliary
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    // Start solving the Tower of Hanoi problem with n disks
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
