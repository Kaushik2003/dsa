#include <iostream>

int main() {
    int num1, num2, sum;

    // Ask the user to enter the first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Ask the user to enter the second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Calculate the sum
    sum = num1 + num2;

    // Display the result
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << std::endl;

    return 0;
}