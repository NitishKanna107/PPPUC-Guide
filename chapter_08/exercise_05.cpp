/*
Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence, leaving its original vector
unchanged. The other reverse function should reverse the elements of its vector without using any other vectors (hint:
swap).

COMMENT:

I could come up with two ways of doing this. One possible way is to loop through the vector similar to how you would do it in 
a bubble sort algorithm and swap the elements left to right without any comparisons between them. This would be fine for small vectors
but it becomes highly inefficient for large vectors.

The better way is to swap first element with the last, second element with the second to last, and so on until we reach the middle
element (if v.size() is odd) or the element just before the middle element (if v.size() is even). I will implement this as it is more
effective and simple.

*/

#include"std_lib_facilities.h"

vector<int> reversed(const vector<int>& v)
{
	vector<int> v_rev;
	for (int i = v.size() - 1; i >= 0; --i) v_rev.push_back(v[i]); // copy backwards
	return v_rev;
}

void reverse(vector<int>& v)
{	
	int j = v.size() - 1; // index from last element
	for (int i = 0; i < v.size()/2; ++i) {
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

void print(const vector<int>& v)
{
	for (int i : v) std::cout << i << ' ';
	std::cout << '\n';
}

int main()
{
	vector<int> nums = { 4,5,6,7 };
	reverse(nums);
	print(nums);
	
	print(reversed(nums)); //reverse again
}