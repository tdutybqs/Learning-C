#include <iostream>


void cycles() {
	// for, while, do-while

	// At first, for 
	// start, conditions, step
	// Variable "i" is local variable
	for (int i = 0; i < 10; ++i) {
		std::cout << "i = " << i << "\t";
	}
	std::cout << std::endl;
	// While
	// variable - counter
	int j = 0;
	// conditions
	while (j < 10) {
		std::cout << "j = " << j << "\t";
		// step, else cycle is infinite: condition is always true
		++j;
	}
	std::cout << std::endl;

	// Do-while
	// variable - counter
	int m = 0;
	do {
		std::cout << "m = " << m << "\t";
		// step
		++m;
	} while (m < 0);
	std::cout << std::endl;

	// Do-while VS while
	// While first check the condition
}

void squares() {
	int i = 0;
	std::cout << "Enter number: ";
	std::cin >> i;
	for (int j = 0; j < i; ++j) {
		std::cout << j * j << "\t";
	}
}