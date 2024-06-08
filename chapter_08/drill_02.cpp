/*
Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const int&, const int&). Each should
have the body
{ int temp; temp = a, a=b; b=temp; }
where a and b are the names of the arguments.
Try calling each swap like this:
	int x = 7;
	int y =9;
	swap_?(x,y); // replace ? by v, r, or cr
	swap_?(7,9);
	const int cx = 7;
	const int cy = 9;
	swap_?(cx,cy);
	swap_?(7.7,9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_?(dx,dy);
	swap_?(7.7,9.9);

Observation:

swap_v:
	All calls compiled successfully. In the first call the values of x and y were not actually swapped as the function swaps only the copies of x and y. The
	same applies for the fifth call. 
swap_r:
	Couldn't compile the second call and the fourth call as we are passing in constants (7, 9, 7.7) and not memory addresses that the function can refer to.
	The third call fails as a conversion from const int to int& cannot be done by the compiler. Similarly, in the last call a double to int& conversion is not possible.
swap_cr:
	The problem doesn't seem to be with the function call but rather the function itself. We cannot modify constant references even if we were to pass a const int as argument. In case 
	you are wondering how swap_cr(7, 9) and swap_cr(7.7, 9.9) are legal, its because const int& is initialized to a constant.
*/

#include"std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	std::cout << "swap_v:" << '\n';
	std::cout << "\ta = " << a << '\n';
	std::cout << "\tb = " << b << '\n';
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	std::cout << "swap_r:" << '\n';
	std::cout << "\ta = " << a << '\n';
	std::cout << "\tb = " << b << '\n';
}

void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	std::cout << "swap_cr:" << '\n';
	std::cout << "\ta = " << a << '\n';
	std::cout << "\tb = " << b << '\n';
}

int main()
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	swap_v(7, 9);
	
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	
	swap_v(7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
}