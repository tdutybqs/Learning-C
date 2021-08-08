#include <iostream>

// The any function must be defined before being called

int example_parameters(int x, int b) {
	// this function has two parameters of the "int" type - x, b.
	// the function must return an "int" type response
	// key-word return
	std::cout << "i" << std::endl; // <- this line will be executed.
	return x * b;
	std::cout << "i" << std::endl; // <- this line will not be executed.
}

void default_parameters(int x, int b = 4) {
	// if function will be executed with 1 parameters, then b will be = 4
	// the standard parameter should be at the end
	std::cout << "x = " << x << "\t" << "b = " << b << std::endl;
}

void description_function() {
	// type name(parameters){ body }
	// void, int, bool, etc - the type of the returned value
	// name - any
	// parameters - any
	example_parameters(10, 20);
	default_parameters(10);
}
