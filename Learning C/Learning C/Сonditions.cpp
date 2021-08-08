#include <iostream>

void conditions() {
	// Operator if
	// ax^2 + bx + c = 0

	// Conditions operator
	int a = 2;
	int b = 4;
	int c = 4;
	int d = b * b - 4 * a * c;
	if (d > 0) {
		std::cout << "Root is " << 2 << std::endl;
	}
	else if (d == 0) {
		std::cout << "Root is " << 1 << std::endl;
	}
	else {
		std::cout << "Root is " << 0 << std::endl;
	}

	// Ternary operator
	int number;
	std::cout << "Number: ";
	std::cin >> number;
	int result = number > 10 ? number * 10 : number / 10;
	std::cout << "Result is " << result << std::endl;
}