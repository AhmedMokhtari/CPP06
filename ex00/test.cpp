#include <iostream>

int main() {
    int intValue = 42;       // Initialize an integer
    float *floatValue = reinterpret_cast<float*>(&intValue);  // Reinterpret the memory of int as float

    std::cout << "Before changing:" << std::endl;
    std::cout << "intValue: " << intValue << std::endl;   // Print original int value
    std::cout << "floatValue: " << *floatValue << std::endl; // Print the reinterpreted float value

    // Change the int value
    intValue = 100;

    std::cout << "\nAfter changing intValue:" << std::endl;
    std::cout << "intValue: " << intValue << std::endl;   // Print the updated int value
    std::cout << "floatValue: " << *floatValue << std::endl; // Print the unchanged float value (reinterpretation shows old value)

    return 0;
}
