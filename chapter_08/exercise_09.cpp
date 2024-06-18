// Written by Nitish Kanna
// 17/6/2024

/*

Objective:
- pass two vector<double>s price and weight to function
- compute sum of price[i]*weight[i]
- print result

*/

/*

I have assumed that we need to calculate the net
price (index) given the price per weight and weight values. 

Algorithm:
- get price and weight values and store them in respective vectors
- return computed index value
- print result

*/

#include"std_lib_facilities.h"

void get_values(vector<double>& price, vector<double>& weight)
{
	std::cout << "Input price per weight and weight values" << '\n';
	std::cout << "End by entering -1 for price" << '\n';

	double p, w;
	while (std::cin >> p >> w) {
		if (!std::cin) error("get_values: bad input");
		if (p == -1) break;

		price.push_back(p);
		weight.push_back(w);
	}
}

double compute(const vector<double>& price, const vector<double>& weight)
{
	if (price.size() != weight.size()) error("compute: vector sizes don't match");

	double index = 0;
	for (int i = 0; i < price.size(); ++i) index += price[i] * weight[i];
	return index;
}

int main()
{
	try {
		vector<double> price;
		vector<double> weight;
		get_values(price, weight);
		std::cout << "Index: " << compute(price, weight) << '\n';
		return 0;
	}
	catch (runtime_error& err) {
		std::cerr << "# " << err.what() << '\n';
		return -1;
	}
}