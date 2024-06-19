// Written by Nitish Kanna
// 19/06/2024

/*
Objective:
- Improve and test the function print_until_s() from 8.5.2
*/

/*
print_until_s() enhancements:
- pass by const reference to avoid expensive copying
- avoid range based for loop to prevent string copying 
  for each element in the vector. Better access it directly.
*/

#include"std_lib_facilities.h"

void print_until_s(const vector<std::string>& v, const std::string& quit) 
{
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit) return;
		std::cout << v[i] << '\n';
	}
}

void print_until_ss(const vector<std::string>& v, const std::string& quit)
{
	bool seen = false;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit) {
			if (seen) return;
			seen = false;
			continue; // don't print quit
		}
		std::cout << v[i] << '\n';
	}
}

int main()
{
	vector <std::string> words = { "hello", "world", "programming", ";", "in", "C++", ";", "is", "fun" };
	print_until_s(words, ";");
	print_until_ss(words, ";");
}