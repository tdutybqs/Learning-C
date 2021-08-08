#include <iostream>

// References are used to solve some pointer problems
// Reference - wrapper over pointers


void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}


void reference() {
	int a = 10;
	int b = 20;
	std::cout << "A = " << a << "\tB = " << b << std::endl;
	swap(a, b);
	std::cout << "A = " << a << "\tB = " << b << std::endl;
	// The reference can't be unitialized
	int* p; // OK
	// int& l; // Error
	// The reference is const
	// Reference hasn't an null value
	// Reference hasn't arithmetic
}