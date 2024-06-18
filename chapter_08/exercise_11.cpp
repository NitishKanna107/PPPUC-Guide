// Written by Nitish Kanna
// 18/06/2024

/*
Objective:
- Function that finds the smallest and largest element of vector
- Function that computes mean and median
- Return everything in a struct
*/

/*
Wrapping the computed values in a struct and returning it is the simplest way to
do this as it makes sure that the code is clean and scalable. 

Imagine if we wanted to calculate and return the mode as well. We could simply create a new variable in the result struct
to store the mode value. Much easier than passing it as a reference. 

This way we also make the user's life a million times easier (imagine having to create 5 variables and pass them as references).
*/

#include"std_lib_facilities.h"

struct result
{
	double mean = 0;
	double median;
	
	double smallest;
	double largest;
};

void printr(const result& rlt, const vector<double>& nums, const std::string& label)
{
	std::cout << label << " {" << '\n';
	std::cout << "  (";
	for (int i = 0; i < nums.size() - 1; ++i) { // loop till second last element so that no comma is printed after last element
		std::cout << nums[i] << ", ";
	}
	std::cout << nums.back();
	std::cout << ")" << '\n';

	std::cout << "  Largest : " << rlt.largest << '\n';
	std::cout << "  Smallest: " << rlt.smallest << '\n';
	std::cout << "  Mean    : " << rlt.mean << '\n';
	std::cout << "  Median  : " <<  rlt.median << '\n';
	std::cout << "}" << '\n';
}

result compute(vector<double> val) // copy vector as we will sort it
{
	if (val.size() == 0) error("!Empty vector");
	std::sort(val.begin(), val.end()); // sort to find median, smallest, largest

	result r;
	r.largest = val.back();
	r.smallest = val.front();

	for (double x : val) {
		r.mean += x;
	}
	r.mean /= val.size();

	int index = val.size() / 2; // index of the middle element

	if (val.size() % 2 != 0) {
		r.median = val[index];
	}
	else {
		r.median = (val[index] + val[index - 1]) / 2.0; // average of the two middle elements
	}
	return r;
}

int main()
{
	try {
		vector<double> nums1 = { 5.5, 3, 2, 6.6, 0 };
		result computed1 = compute(nums1);
		printr(computed1, nums1, "test_case1");

		vector<double> nums2 = { 1.5, 5.6, 3 };
		result computed2 = compute(nums2);
		printr(computed2, nums2, "test_case2");
		
		// Triggers an error
		vector<double> nums3 = { };
		result computed3 = compute(nums3);
		printr(computed3, nums3, "test_case3");

		return 0;
	}
	catch (runtime_error& err) {
		std::cerr << "!" << err.what() << '\n';
		return -1;
	}
	catch (...) {
		std::cerr << "!Unknown exception" << '\n';
		return -2;
	}
}