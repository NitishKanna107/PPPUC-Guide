// Written by Nitish Kanna
// 17/6/2024

/*
Objective:
- Write a function maxv() that returns the largest element of a vector argument
*/

/*
For now, maxv() will accept only int, double, char, and string vectors and return the 
largest element of the vector passed as an argument. Template arguments is the ideal
solution but since we haven't learnt it yet we will just use function overloading.
*/

// Read about function overloading - https://learn.microsoft.com/en-us/cpp/cpp/function-overloading?view=msvc-170

#include"std_lib_facilities.h"

double maxv(const vector<double>& values)
{
	if (values.empty()) error("maxv: empty vector");

	double largest = values[0];
	for (int i = 0; i < values.size(); ++i) if (values[i] > largest) largest = values[i];
	return largest;
}

int maxv(const vector<int>& values)
{
	if (values.empty()) error("maxv: empty vector");

	int largest = values[0];
	for (int i = 0; i < values.size(); ++i) if (values[i] > largest) largest = values[i];
	return largest;
}

char maxv(const vector<char>& values)
{
	if (values.empty()) error("maxv: empty vector");

	char largest = values[0];
	for (int i = 0; i < values.size(); ++i) if (values[i] > largest) largest = values[i];
	return largest;
}

std::string maxv(const vector<std::string>& values)
{
	if (values.empty()) error("maxv: empty vector");

	std::string largest = values[0];
	for (int i = 0; i < values.size(); ++i) if (values[i] > largest) largest = values[i];
	return largest;
}

int main()
{
	try {
		vector<double> d = { 9.4, 5.5, 3.42, 1.1 };
		std::cout << "Largest double: " << maxv(d) << '\n';

		vector<int> i = { 5, 34, 10, 20 };
		std::cout << "Largest int: " << maxv(i) << '\n';

		vector<char> c = { 'a', 'A', '4', '#', 'h' };
		std::cout << "Largest char: " << maxv(c) << '\n';

		vector <std::string> s = { "hello", "world", "apple", "lion", "Bear" };
		std::cout << "Largest string: " << maxv(s) << '\n';
		return 0;
	}
	catch (runtime_error& err) {
		std::cerr << "# " << err.what() << '\n';
		return -1;
	}
	catch (...) {
		std::cerr << "# Unknown exception" << '\n';
		return -2;
	}
}