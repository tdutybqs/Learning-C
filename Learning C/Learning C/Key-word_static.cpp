#include <iostream>

struct Apple {
	Apple() { ++count; }
	static size_t count;
};

size_t Apple::count = 0; // <- common for all apple

void static_key_word() {
	Apple a;
	Apple a_2;
	std::cout << a.count << std::endl;
	std::cout << a_2.count << std::endl;
}