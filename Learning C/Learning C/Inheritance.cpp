#include <iostream>

struct Person {
public:
	Person(std::string name, size_t age) : name_(name), age_(age) {};
	void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ << std::endl;
	}
protected: // <- if the fields have an "private" modifier, the derived class does not have access to the fields
	// because out modifier an "protected"
	std::string name_;
	size_t age_;
};


struct Student : public Person{
public:
	Student(std::string name, size_t age, std::string group) : Person(name, age), group_(group) {};
	void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ <<", group is "<< group_ << std::endl;
	}
private:
	std::string group_;
};


void Inheritance() {
	Person ivan("Ivan", 13);
	Person vlad("Vlad", 14);
	ivan.Print_information();
	vlad.Print_information();
	Student ivan_student("Ivan", 16, "IST");
	ivan_student.Print_information();
}