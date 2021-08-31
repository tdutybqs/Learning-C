#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>


int count = 200;


void other_function() {
	for (int i = 0; i < 10; ++i) {
		std::cout <<"thread id: " << std::this_thread::get_id() << " void other_function " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(count));
	}
}


void no_thread() {
	std::cout << "Start no_thread" << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << "thread id: " << std::this_thread::get_id() << " void thread " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(count));
	}
	other_function(); // <- start after previous cycle
	std::cout << "End no_thread" << std::endl;
}


void thread_join() {
	std::cout << "Start thread" << std::endl;
	std::thread my_thread(other_function);
	for (int i = 0; i < 10; ++i) {
		std::cout << "thread id: " << std::this_thread::get_id() << " void thread " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(count));
	}
	my_thread.join(); // Work until the thread ends
	std::cout << "End thread" << std::endl;
}


void thread_detach() {
	std::cout << "Start thread" << std::endl;
	std::thread my_thread(other_function);
	for (int i = 0; i < 10; ++i) {
		std::cout << "thread id: " << std::this_thread::get_id() << " void thread " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	my_thread.detach(); // Work until the main_thread ends
	std::cout << "End thread" << std::endl;
}


void calculate(int a, int b) {
	std::cout << "Thread id " << std::this_thread::get_id()<<"\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	std::cout << a << " / " << b << " = " << a / b << std::endl;
}


void transfer_parameters() {
	int a = 10;
	int b = 20;
	std::thread my_thread(calculate, a, b);
	my_thread.join();
}


void print_vector(std::vector<int>& a) {
	for (auto& i : a) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}


void sort(std::vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size() - 1; ++j) {
			if (a[i] < a[j]) std::swap(a[i], a[j]);
		}
	}
}


void sort_thread(std::vector<int>& a) {
	for (int i = 0; i < a.size() / 2; ++i) {
		for (int j = 0; j < a.size() / 2 - 1; ++j) {
			if (a[i] < a[j]) std::swap(a[i], a[j]);
		}
	}
}


void sort_with_thread() {
	auto start = std::clock();
	std::srand(std::time(NULL));
	std::vector<int> my_vector;
	for (int i = 0; i < 1000; ++i) {
		my_vector.push_back(std::rand() % 100);
	}

	std::thread th(sort_thread, std::ref(my_vector)); // for refer by reference
	for (int i = my_vector.size()/2; i < my_vector.size(); ++i) {
		for (int j = my_vector.size()/2; j < my_vector.size() / 1; ++j) {
			if (my_vector[i] < my_vector[j]) std::swap(my_vector[i], my_vector[j]);
		}
	}
	th.join(); // wait the thread
	
	auto end = std::clock();
	std::cout << "\nTime: "<< end - start << std::endl;
	print_vector(my_vector);
}


int sum_a_b(int a, int b) {
	std::cout << "ID: " << std::this_thread::get_id() << "------------------Work start" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "ID: " << std::this_thread::get_id() << "------------------Work end" << std::endl;
	return a + b;
}


class test {
public:
	test(int a, int b) : _a(a), _b(b) {};
	void PrintValues() {
		std::cout << "A = " << _a << "\tB = " << _b << std::endl;
	}
	void ChangeA(int a) {
		std::cout << "ID: " << std::this_thread::get_id() << "------------------Work start" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "ID: " << std::this_thread::get_id() << "------------------Work end" << std::endl;
		_a = a;
	}
private:
	int _a = 0;
	int _b = 0;
};


void return_value() {
	int a = 10;
	int b = 20;
	int result = 0;
	std::thread t([&]() {
		result = sum_a_b(a, b);
		}); // well
	for (int i = 0; i < 10; ++i) {
		std::cout << "ID: " << std::this_thread::get_id() << "\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		t.join(); //wait thread
		std::cout << "Result = " << result << std::endl;
	}
}


void thread_class() {
	test newObject(10, 20);
	newObject.PrintValues();
	//std::thread m(newObject.ChangeA(40)); // error
	std::thread t([&]() {
		newObject.ChangeA(30);
		});
	for (int i = 0; i < 10; ++i) {
		std::cout << "ID: " << std::this_thread::get_id() << "\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	} // load
	t.join(); // wait thread
	newObject.PrintValues();
}