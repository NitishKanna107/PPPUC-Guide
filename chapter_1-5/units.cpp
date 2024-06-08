#include"std_lib_facilities.h"

int main()
{
	double num;
	double smallest = INT_MAX, largest = 0;
	double sum = 0;
	int val_no = 0;

	std::string unit;
	vector<double> values;

	constexpr double m_cm = 100;
	constexpr double in_cm = 2.54;
	constexpr double ft_in = 12;

	while (std::cin >> num >> unit)
	{
		std::cout << "Value entered: " << num << unit << '\n';

		if (unit == "in") {
			num = num * in_cm / m_cm;
		}
		else if (unit == "ft") {
			num = num * ft_in * in_cm / m_cm;
		}
		else if (unit == "cm") {
			num = num / m_cm;
		}
		else if(unit != "m") {
			std::cout << "Illegal unit\n";
			continue;
		}

		values.push_back(num);
		sum += num;
		val_no += 1;

		if (num <= smallest) {
			smallest = num;
		}
		else if (num >= largest) {
			largest = num;
		}
	}

	sort(values);

	std::cout << "Sum of values: " << sum << " m" << '\n';
	std::cout << "Largest value: " << largest << " m" << '\n';
	std::cout << "Smallest value: " << smallest << " m" << '\n';
	std::cout << "Number of values: " << val_no << '\n';
	std::cout << "Median value: ";

	if (values.empty()) {
		std::cout << "None" << '\n';
	}
	else if (values.size() % 2 != 0) {
		std::cout << values[values.size() / 2] << '\n';
	}
	else if(values.size() != 1){
		int index = values.size() / 2;
		std::cout << (values[index] + values[index - 1]) / 2 << '\n';
	}
	else {
		std::cout << values[0] << '\n';
	}

	for (double i : values) {
		std::cout << i << " m" << '\n';
	}
}