#include <iostream>

void lvalue() {
	// References refer only to lvalue
	int a = 10;
	int b = 20;
	// l1 is lvalue reference
	int& l1 = a; // Ok, a is lvalue
	// int& l2 = a * 2; // Error, a*2 is rvalue
	// l2 is lvalue reference
	int& l2 = (a * 2 > 20 ? a : b); // Ok
}

void rvalue() {
	// rvalue - temp object
	int&& b = 10; // Ok, b is rvalue reference

}