#include <iostream>

struct IntArray {
	IntArray(size_t size, int value) : size_(size), data_(new int[size]) {
		for (int i = 0; i < size_; ++i) {
			data_[i] = value;
		}
	};
	IntArray(const IntArray& other) : size_(other.size_), data_(new int[other.size_]) {
		for (int i = 0; i < size_; ++i) {
			this->data_[i] = other.data_[i];
		}
	}
	void Print() {
		for (int i = 0; i < size_; ++i) {
			std::cout << data_[i] << " ";
		}
	}
	IntArray& operator =(const IntArray& other) {
		if (this != &other) {
			delete[] data_;
			size_ = other.size_;
			data_ = new int[size_];
			for (int i = 0; i < other.size_; ++i) {
				data_[i] = other.data_[i];
			}
		}
		return *this;
	}

private:
	size_t size_;
	int* data_;
};


void copy_const() {
	IntArray i(10, 11);
	IntArray j = i; // <- copy const
	IntArray g(12, 20);
	i.Print();
	std::cout << std::endl;
	j.Print();
	std::cout << std::endl;
	j = g; // <- operator assignment
	j.Print();
	std::cout << std::endl;
}