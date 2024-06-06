#include "std_lib_facilities.h"

vector<double> solve_quad(double a, double b, double c);

int main()
{
	try
	{
		double a, b, c = 0;

		while (std::cin >> a >> b >> c)
		{
			vector<double> roots = solve_quad(a, b, c);
			std::cout << "Roots: " << roots[0] << ", " << roots[1] << '\n';
		}

		if (!std::cin)
			throw runtime_error("Bad input passed!!!");
		
	}
	catch (runtime_error& err)
	{
		std::cout << "Error: " << err.what() << '\n';
	}
}

vector<double> solve_quad(double a, double b, double c)
{
	double det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		throw runtime_error("Quadratic has no real roots!!");
	
	double x1 = (sqrt(det) - b) / (2 * a);
	double x2 = (-sqrt(det) - b) / (2 * a);

	return { x1, x2 };
}