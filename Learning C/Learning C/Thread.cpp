#include <iostream>
#include <thread>
#include <chrono>

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
