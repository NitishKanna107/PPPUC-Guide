// Written by Nitish Kanna
// 17/6/2024

/*
Objective:

- Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages
  in a vector<double> age. 
- Then print out the five (name[i],age[i]) pairs. 
- Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs.
- Repeat steps with arbitrary number of names
*/

/*
Algorithm:

- Get five (or an arbitrary number of) names
- Get the corresponding ages
- Print the unsorted (name, age) pairs
- Copy names vector to n_clone vector and then sort names vector
- Print the sorted (name, age) pairs
	+ For every name in the names vector find its index value in n_clone vector
	+ Using the index value get the age value from ages vector
*/

#include"std_lib_facilities.h"

void get_pairs(int n, vector<std::string>& names, vector<int>& ages)
{
	constexpr char push = ';';
	constexpr char end = '|';

	std::cout << "End each name with " << push << '\n';
	std::cout << "End input with " << end << '\n';

	int i = 1;
	while (i != n) {
		std::string name;

		// Each name is separated by push char
		char ch;
		while (std::cin.get(ch), ch != push) {
			if (ch == end) {
				if (n > 0) error("Ending too soon"); // In case user ends before entering required number of names
				i = n - 1;							 // In order to exit the while loop
				break;
			}
			if (ch != '\n') name += ch;
		}
		if(!name.empty()) names.push_back(name);
		++i;
	}

	for (int i = 0; i < names.size(); ++i) {
		std::cout << "Age of " << names[i] << ": ";
		
		int age;
		std::cin >> age;
		if (!std::cin) error("Bad input");
		ages.push_back(age);
	}
}

void print_sorted(const vector<std::string>& names, const vector<std::string>& clone, const vector<int>& ages)
{
	for (std::string name : names) {
		// std::distance is a function that returns the number of hops
		// you need to take from the beginning of the vector to the
		// position where name is found
		int index = std::distance(clone.begin(), std::find(clone.begin(), clone.end(), name));
		std::cout << "(" << name << ", " << ages[index] << ")\n";
	}
}

void print_unsorted(const vector<std::string>& names, const vector<int>& ages)
{
	for (int i = 0; i < names.size(); ++i)
		std::cout << "(" << names[i] << ", " << ages[i] << ")\n";
}

int main()
{
	try {
		std::cout << "-------(Name, Age) Program-------" << '\n';

		vector<std::string> names;
		vector<int> ages;
		
		// std::cout << "Enter five names:" << '\n';
		// get_pairs(5, names, ages);

		std::cout << "Enter names:" << '\n';
		get_pairs(-1, names, ages); // the first param (number of names) can be any negative number if you 
									// want to get an arbitrary number of names

		std::cout << "\nBefore sorting names:" << '\n';
		print_unsorted(names, ages);

		vector<std::string> n_clone = names;
		std::sort(names.begin(), names.end()); // sorts in ascending order by default

		std::cout << "\nAfter sorting names:" << '\n';
		print_sorted(names, n_clone, ages);
		return 0;
	}
	catch (runtime_error& err) {
		std::cerr << "# " << err.what() << '\n';
		return -1;
	}
	catch (out_of_range& err) {
		std::cerr << "# Vector out of bounds" << '\n';
	}
	catch (...) {
		std::cerr << "# Unknown exception" << '\n';
		return -2;
	}
}