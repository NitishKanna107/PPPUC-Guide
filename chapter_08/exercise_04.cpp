/*
An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using
fibonacci().
*/

#include"std_lib_facilities.h";

void print(const vector<int>& nums, const std::string& label)
{
	// Not the most exquisite way to represent a vector on screen
	// but will do for now.
	std::cout << label << '\n';
	for (int i : nums)
		std::cout << i << '\n';
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v = { x, y };

	int num1 = y;
	int num2 = x + y;

	for (int i = 2; i <= n; ++i) { // start from 2 as x and y are already pushed to v
		v.push_back(num2);
		num2 += num1;
		num1 = v.back();
	}
}

int main()
{
	vector<int> fib_seq;
	fibonacci(0, 1, fib_seq, 5);			// The largest value that could be stored in fib_seq - 1836311903
	print(fib_seq, "Fibonacci Sequence");	
}