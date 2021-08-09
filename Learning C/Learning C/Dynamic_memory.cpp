#include <iostream>
#include <cstdlib> // malloc, free, calloc, realloc

void example_1();
void example_2();

void dynamic_memory() {
	// Stack is limited
	// Two methods allocate dynamic memory

	// C-style
	void* malloc(size_t size); // allocate memory >= size; Data is uninitialize
	void free(void* ptr); // Deallocate memory
	void* calloc(size_t nmemb, size_t size); // == malloc. For arrays. Data is initialize
	void* realloc(void* ptr, size_t size); // Change size memory
	example_1();


	// C++ style
	// Two operators for allocate and two operators for deallocate
	// delete, new <-- for single values
	// delete[], new[]  <-- for arrays
	example_2();
}


void example_1() {
	// malloc return void*. We need void* to int*
	int* m = (int*)malloc(1000 * sizeof(int)); // sizeof() - return size
	std::cout << "Malloc:\n" << m[0] << std::endl; // Don't initialize
	m = (int*)realloc(m, 2000 * sizeof(int)); // expansion memory for array
	free(m); // deallocate
	m = (int*)calloc(3000, 2000 * sizeof(int));
	std::cout << "Calloc:\n" << m[0] << std::endl; // Data is initialize
	free(m);
}


void example_2() {
	int* m = new int[200];
	std::cout << "New[]:\n" << m[0] << std::endl;
	delete[] m;

	m = new int(4);
	std::cout << "New:\n" << m[0] << std::endl;
	delete m;
}