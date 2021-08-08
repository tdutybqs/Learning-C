#include <iostream>


// Pointer - pollute the code (we need to use * and &)
// nullptr
// Pointer arithmetic - you may get an invalid pointer


void swap(int* a, int* b);

void pass_array(int* array, int size);

void pointer() {
	// Pointers - save address
	// nullptr - null pointers
	int i = 3;
	int* i_ptr = &i; // & - take address
	std::cout << "i_ptr refers to = " << i_ptr << "\t" << "i = " << &i << std::endl; // i_ptr == &i
	std::cout << "Address i_ptr = " << &i_ptr << "\t" << "Address i = " << &i << std::endl; // address i_ptr != &i
	std::cout << "Get value from i_ptr = " << *i_ptr << std::endl; // stdout value from variable "i" - 3
	*i_ptr = 10; // Change value i_ptr
	std::cout << *i_ptr << "\t" << i << std::endl; // i also is changed
	int a = 10;
	int b = 20;
	std::cout << "A is " << a << "\t" << "B is " << b << std::endl;
	swap(&a, &b);
	std::cout << "Swap(a, b)" << std::endl;
	std::cout << "A is " << a << "\t" << "B is " << b << std::endl;
}

// reference by value - create a copy, reference by pointer - do not create a copy
// We get the address of the variable
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void arrays() {
	// arrays are created on the stack
	int m[10] = { 1, 2, 33, 4, 56, 7 }; // m[10] - allocate memory for 10 elements
	// Index - the number of the element in the array
	// element "1" has index is "0"
	// element "2" has index is "1"
	// element "33" has index is "2"
	// ....
	// element "7" has index is "5"
	std::cout << m[0] << std::endl; // stdout element by index "0"
	// i < 10, because we have a ten elements
	for (int i = 0; i < 10; ++i) {
		std::cout << m[i] << " ";
	}
	std::cout << std::endl;

	// Pointer arithmetic
	std::cout << "Address = " << m << "\tValue = " << *m << std::endl; // We will see the address of the element from the index "0"
	// m - pointer
	std::cout << "Address = " << m + 4 << "\tValue = " << *(m + 4) << std::endl; // We move the pointer to 4 positions
	// possible operations = -, +
	// m[k] == *(m + k)
	// Arrays reference to functions by pointer, not by value!
	// We must pass the size of our array
	// for example, foo(array, size);
	pass_array(m, 10);
}

void pass_array(int* array, int size) {
	for (int i = 0; i < size; ++i) { // Therefore, it is important to know the size of the array
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}