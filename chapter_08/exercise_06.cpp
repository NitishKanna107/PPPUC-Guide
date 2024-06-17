// Author: Nitish Kanna
// Date: 9/6/2024

/*
Write versions of the functions from exercise 5, but with a vector<string>
*/

// Just change all vector<int> to vector<string>

#include"std_lib_facilities.h"

vector<std::string> reversed(const vector<std::string>& v)
{
	vector<std::string> v_rev;
	for (int i = v.size() - 1; i >= 0; --i) v_rev.push_back(v[i]); // copy backwards
	return v_rev;
}

void reverse(vector<std::string>& v)
{
	int j = v.size() - 1; // index from last element
	for (int i = 0; i < v.size() / 2; ++i) {
		swap(v[i], v[j]);
		--j;
	}

	// The below alternate method is quite similar
	// to the bubble sort algorithm. The only 
	// difference is we don't have to do any comparisons but
	// only swap elements left to right.

	/*
	for (int i = 0; i < v.size() - 2; ++i) {
		for (int j = i; j < v.size(); ++j) {
			swap(v[i], v[j]);
		}
	}
	*/
}

void print(const vector<std::string>& v)
{
	for (std::string i : v) std::cout << i << ' ';
	std::cout << '\n';
}

int main()
{
	vector<std::string> nums = { "hello", "hey", "hola", "amigo" };
	reverse(nums);
	print(nums);

	print(reversed(nums)); //reverse again
}