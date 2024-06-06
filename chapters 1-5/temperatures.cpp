#include "std_lib_facilities.h"

int main()
{
	vector<double> tempsc;
	std::cout << "Input temperatures in C$ ";

	for (double temp; std::cin >> temp;)
	{
		tempsc.push_back(temp);
	}
	
	vector<double> tempsf;
	double sum_C = 0;
	double sum_F = 0;

	for (double tempC : tempsc)
	{
		double tempF = tempC * 9.0 / 5 + 32;
		tempsf.push_back(tempF);

		sum_C += tempC;
		sum_F += tempF;
	}

	std::cout << "Conversions done:" << '\n';
	for (int i = 0; i < tempsc.size(); i++)
	{
		std::cout << tempsc[i] << " C" << " -> " << tempsf[i] << " F" << '\n';
	}
	
	std::cout << "Average temperature(C): " << sum_C / tempsc.size() << '\n';
	sort(tempsc);
	std::cout << "Median temperature(C): " << tempsc[tempsc.size() / 2] << '\n';

	std::cout << "Average temperature(F): " << (sum_C * 9.0 / 5 + 32 * tempsf.size()) / tempsc.size() << '\n';
	sort(tempsf);
	std::cout << "Median temperature(F): " << tempsf[tempsf.size() / 2] << '\n';
}