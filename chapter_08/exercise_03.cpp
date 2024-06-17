/*
Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a
function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and n is the number of
elements to put into v; v[0] will be x and v[1] will be y. 

A Fibonacci number is one that is part of a sequence where each
element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . . Your
fibonacci() function should make such a sequence starting with its x and y arguments.
*/

#include"std_lib_facilities.h"

void print(const vector<int>& nums, const std::string& label)
{
	std::cout << label << '\n';
	for (int i : nums)
		std::cout << i << '\n';
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v = { x, y };

	int num1 = y;
	int num2 = x + y;

	for (int i = 2; i < n; ++i) { // start from 2 as x and y are already pushed to v
		v.push_back(num2);
		int tmp = num2;
		num2 += num1;
		num1 = tmp;
	}
}

int main()
{
	vector<int> fib_seq;
	fibonacci(0, 1, fib_seq, 5);
	print(fib_seq, "Fibonacci Sequence");
}