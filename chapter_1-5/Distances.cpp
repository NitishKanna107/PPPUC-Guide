#include"std_lib_facilities.h"

int main()
{
	vector<double> distances;
	double distance;

	while (std::cin >> distance) {
		distances.push_back(distance);
	}

	if (!distances.empty()) {
		sort(distances);
		std::cout << "Median distance: ";

		if (distances.size() % 2 != 0) {
			std::cout << distances[distances.size() / 2] << '\n';
		}
		else if (distances.size() != 1) {
			int index = distances.size() / 2;

			if (index != 0)
				std::cout << (distances[index] + distances[index - 1]) / 2 << '\n';
			else
				std::cout << distances[0] << '\n';
		}

		std::cout << "Smallest: " << distances[0] << '\n';
		std::cout << "Largest: " << distances.back() << '\n';

		double sum = 0;
		for (double dist : distances) sum += dist;

		std::cout << "Sum: " << sum << '\n';
	}
	else {
		std::cout << "You didn't enter any distances!\n";
	}
}