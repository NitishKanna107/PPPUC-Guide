/*
Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and
3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value.
Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character '5' subtract '0',
that is, '5'–'0'==5.
*/

#include"std_lib_facilities.h"

int main()
{
	vector<std::string> value = { "one", "ten", "hundred", "thousand" };
	constexpr char print = ';';

	std::cout << "Integer Composer" << '\n';
	std::cout << "Input a number less than 10000 and greater than or equal to 0" << '\n';
	std::cout << "End input number with a ';'" << '\n';
	std::cout << "Use Ctrl+Z or Ctrl+D to quit" << '\n';

	try {
		while (std::cin)
		{
			vector<char> digits;
			
			std::cout << "> ";
			for (char digit; std::cin >> digit;) {
				if (digits.size() > 4) error("Too many digits to read");
				if (digit == print) break;
				if (digit < '0' || digit > '9') error("Bad input");

				digits.push_back(digit);
			}

			// Initialize power to get decimal place
			// during each iteration
			int num = 0;
			int power = digits.size() - 1;

			for (int i = 0; i < digits.size(); ++i) {
				int digit = digits[i] - '0';
				std::cout << digit << " " << value[power];
				num = (num * 10) + digit;

				if (digit > 1) std::cout << "s";
				if (power != 0) std::cout << " and ";

				// Move decimal place one level down
				--power;
			}
			std::cout << "\n" << num << '\n';
		}
	}
	catch (runtime_error& err) {
		std::cout << "# " << err.what() << '\n';
	}
	catch (...) {
		std::cout << "# Unknown exception!" << '\n';
	}
}