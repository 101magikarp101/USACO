#include <iostream>

int main() {
    int i = 42;              // A modifiable integer
    int const& cr = i;       // 'cr' is a constant reference to 'i'

    std::cout << "Initial value of i: " << i << std::endl;
    std::cout << "Value accessed via cr: " << cr << std::endl;

    // We can modify i directly...
    i = 100;
    std::cout << "\nAfter modifying i directly:" << std::endl;
    std::cout << "Value of i: " << i << std::endl;
    std::cout << "Value accessed via cr: " << cr << std::endl;

    // Attempting to modify i through cr would result in a compile-time error:
    // cr = 200; // Uncommenting this line will cause a compiler error

    return 0;
}
