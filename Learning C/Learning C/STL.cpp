#include <iostream>
#include <vector>
#include <list>

template <typename T>
void sort_insertion(T& a) {
	// Insertion
	for (int i = 0; i < a.size(); ++i) {
		for (int j = a.size() - 1; j >= i; --j) {
			if (a[i] < a[j]) {
				std::swap(a[i], a[j]);
			}
		}
	}
}


template <typename T>
void bubble_sort(T& a) {
	// Bubble
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size() - 1; ++j) {
			if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
		}
	}
}

template <typename T>
void print(const T& a) {
	for (auto& i : a) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
}

void run() {
	std::vector<int> a{1,2,3,4,5,6,7,8,9,10};
	print(a);
	sort_insertion(a);
	print(a);
	bubble_sort(a);
	print(a);

	std::list<int> b{ 1,2,3,6,4,5 };
	print(b);
	b.sort();
	print(b);
}