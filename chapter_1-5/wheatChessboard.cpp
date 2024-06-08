#include"std_lib_facilities.h"

int main()
{
	/*
	int grainsNet;

	while (std::cin >> grainsNet) {
		int squares = 0;
		int grains = 1;
		int grainSum = 0;

		while (grainSum < grainsNet) {
			++squares;
			grainSum += grains;
			grains *= 2;
		}

		std::cout << "Squares required: " << squares << '\n';
		std::cout << "Grains gathered: " << pow(2, squares) - 1 << '\n';
	}
	*/

	constexpr int squares = 64;
	uint64_t grainSum = 0;

	for (int i = 1; i <= squares; i++) {
		grainSum += pow(2, (i - 1));
		std::cout << i << " - " << grainSum << '\n';
	}

	std::cout << "Total grains: " << grainSum << '\n';
}