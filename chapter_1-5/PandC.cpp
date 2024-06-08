/*
Author: Nitish Kanna

Description:
Calculate the total number of permutations or combinations according to the
given data - number of objects, and number of choices. Allow the user to choose between
performing a permutation and performing a combination.
*/

#include"std_lib_facilities.h"

int fact(int n)
{
	if (n < 0) error("fact: negative factorial");
	int result = 1;
	for (int i = n; i >= 1; --i) {
		// Disgusting overflow check:
		// In reality result may not always truncate to zero
		// as C++ defines integer overflows to result in 
		// undefined behavior. So don't be surprised if it crashes.
		if (result == 0) error("fact: calculation size exceeded");
		result *= i;
	}
	return result;
}

int permute(int obj, int choices)
{
	if (choices > obj) error("permute: not enough objects to permute");
	return fact(obj) / fact(obj - choices);
}

int combinate(int obj, int choices)
{
	if (choices > obj) error("combinate: not enough objects to combinate");
	return permute(obj, choices) / fact(choices);
}

int calculate()
{
	int obj;
	std::cout << "num.objects$ ";
	std::cin >> obj;
	if (!std::cin) error("Bad input");

	int choices;
	std::cout << "num.choices$ ";
	std::cin >> choices;
	if (!std::cin) error("Bad input");

	char ch;
	std::cout << "permute(p) or combinate(c)$ ";
	std::cin >> ch;

	if (ch == 'p') {
		return permute(obj, choices);
	}
	else if (ch == 'c') {
		return combinate(obj, choices);
	}
	else {
		error("Bad input");
	}
}

int main()
{
	try {
		while (std::cin) {
			std::cout << "=" << calculate() << '\n';
		}
		return 0;
	}
	catch (runtime_error& err) {
		std::cout << "# " << err.what() << '\n';
		return -1;
	}
	catch (...) {
		std::cout << "# Unknown exception!" << '\n';
		return -2;
	}
}