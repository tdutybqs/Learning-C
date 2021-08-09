#include <iostream>


int square(int d) {
	std::cout << "Int" << std::endl;
	return d * d;
}


double square(double d) {
	std::cout << "Double" << std::endl;
	return d * d;
}


/*
* double square(int d) {} <- error. Function can't be overload wih the return vale type
*/


struct Person {
public:
	Person(std::string name, size_t age) : name_(name), age_(age) {};
	void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ << std::endl;
	}
protected:
	std::string name_;
	size_t age_;
};


struct Student : public Person {
public:
	Student(std::string name, size_t age, std::string group) : Person(name, age), group_(group) {};
	using Person::Print_information; // <- use methods from base struct. Person.Print_information()
	void Print_information(std::string) { // <- use methods from derived struct. Student.Print_information()
		std::cout << "Name is " << name_ << ", age: " << age_ << ", group is " << group_ << std::endl;
	}
private:
	std::string group_;
};


void overload() {
	// Overload is work at the compile stages
	std::cout << square(10) << std::endl;
	std::cout << square(10.) << std::endl;

	// Overload methods
	Person a("Ivan", 14);
	a.Print_information();
	Student b("Vlad", 16, "IST");
	b.Print_information();
	b.Print_information("str");
}