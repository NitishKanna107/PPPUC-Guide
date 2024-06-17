/*
Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the output
and a vector.
*/

#include"std_lib_facilities.h"

void print(const vector<int>& nums, const std::string& label)
{
	std::cout << label << '\n';
	for (int i : nums)
		std::cout << i << '\n';
}

int main()
{
	vector<int> values = { 2, 4, 8, 16, 32, 64 };
	print(values, "Geometric Progression");
}