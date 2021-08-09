#include <iostream>


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
	void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ << ", group is " << group_ << std::endl;
	}
private:
	std::string group_;
};


struct Person_2 {
public:
	Person_2(std::string name, size_t age) : name_(name), age_(age) {};
	virtual void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ << std::endl;
	}
protected:
	std::string name_;
	size_t age_;
};


struct Student_2 : public Person_2 {
public:
	Student_2(std::string name, size_t age, std::string group) : Person_2(name, age), group_(group) {};
	void Print_information() {
		std::cout << "Name is " << name_ << ", age: " << age_ << ", group is " << group_ << std::endl;
	}
private:
	std::string group_;
};


void virtual_methods() {
	std::cout << "Problem" << std::endl;

	// Problem
	Person a("Ivan", 14);
	Student b("Vlad", 15, "IST");
	Person* c = &b;
	c->Print_information(); // call methods from derived struct

	std::cout << "Solution" << std::endl;

	// Solution - using key-word "virtual"
	Person_2 aa("Ivan", 14);
	Student_2 bb("Vlad", 15, "IST");
	Person_2* cc = &bb;
	cc->Print_information(); // call methods from derived struct

	// Virtual destructor
	// To properly free up memory, you must use a virtual destructor

	// Overload - static polymorphism. Compile stages
	// virtual - dynamic polymorphism. Runtime
}