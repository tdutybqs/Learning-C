#include <iostream>
#include <initializer_list>

struct Point {
	Point() {}; // default const 
	Point(int x, int y): x(x), y(y) {}; // Constructor 2 parameters
	// key-word expilicit - prohibition of implicit conversion
	// You can't call const with double
	explicit Point(int x): x(x), y(0) {}; // Const with 1 parameters
	Point(std::initializer_list<int> list) { // Const with initialize_list parameters
		for (auto& i : list) {
			std::cout << "Elem = " << i << std::endl;
		}
	}
	~Point() { // <- destructor
		std::cout << "Destructor" << std::endl;
	}
	int x = 0;
	int y = 0;
};


void constructor() {
	Point point_def; // <- call default constructor
	Point point_two_parameters(1, 2); // <- call const with 2 parameters
	Point point_one_parameters(1); // <- call const with 1 parameters
	std::cout << "Point_def X = " << point_def.x << "\t Y = " << point_def.y << std::endl;
	std::cout << "Point_two_parameters X = " << point_two_parameters.x << "\t Y = " << point_two_parameters.y << std::endl;
	std::cout << "Point_one_parameters X = " << point_one_parameters.x << "\t Y = " << point_one_parameters.y << std::endl;
	Point point_list{ 1, 2, 3, 4, 5, 6, 7 }; // <- call initialize const
}

void destructor() {
	// Destructor delete object, deallocate memory
	// Begin with "~"
	// 
}