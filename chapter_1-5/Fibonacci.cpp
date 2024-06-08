#include"std_lib_facilities.h"

int main()
{
	int n;
	std::cin >> n;

	int num1 = 0;
	int num2 = 1;

	std::cout << "1. " << num2 << '\n';

	for (int i = 2; i <= n; i++) {
		int tmp = num2;
		num2 = num1 + num2;
		num1 = tmp;

		std::cout << i << ". " << num2 << '\n';
	}
}