#include <iostream>


struct Point {
public:
	Point(int x, int y) : x(x), y(y) {};
	int Get_x() { return this->x; }
	int Get_y() { return this->y; }
	void Set_x(const int x) { this->x = x; }
	void Set_y(const int y) { this->y = y; }
	void Print_position() { std::cout << "X: " << x << "\tY: " << y << std::endl; }
private:
	int x = 0;
	int y = 0;
};


void structure() {
	// Example, struct name{body};
	// Default access - public
	// "this" current instance of the class
	Point newPoint(1, 2);
	newPoint.Print_position();
	std::cout << newPoint.Get_x() << std::endl;
	std::cout << newPoint.Get_y() << std::endl;
}

