#include"std_lib_facilities.h"

int main()
{
	vector<std::string> nums = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::string input;
	constexpr char zero_ascii = '0';

	while (std::cin >> input) {
		if (input.length() == 1) {
			int numIndex{ input[0] - zero_ascii };

			if (numIndex >= 0 && numIndex <= 9)
				std::cout << nums[numIndex] << '\n';
			else
				std::cout << "You broke me!\n";
		}
		else {
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] == input) {
					std::cout << i << '\n';
					break;
				}
				
				if (i == nums.size() - 1) {
					std::cout << "You broke me!\n";
				}
			}
		}
	}
}