// Written by Nitish Kanna
// 19/06/2024

/*
Objective:
- Write a function that takes a vector<string> and returns a vector<int> 
  containing the number of characters in each string
- Find largest and smallest string
- Find the first and last string that occur lexicographically
*/

/*
Functions:
- word_sizes()  : takes a vector<string> and returns a vector<int> containing the number of characters in each string
- word_stats()  : finds out the largest string, smallest string, and lexicographically first string and last string
- print_stats() : print the Stats struct in an exquisite way 
*/

#include"std_lib_facilities.h"

vector<int> word_sizes(const vector<std::string>& words)
{
	if (words.size() == 0) error("word_sizes(): !Empty vector");

	vector<int> sizes;
	for (std::string word : words) 
		sizes.push_back(word.length());
	return sizes;
}

struct Stats
{
	std::string largest;
	std::string smallest;

	std::string first;
	std::string last;
};

// I decided to write just one function for finding the largest, smallest, first, and last string to
// keep the code minimalistic.

Stats word_stats(const vector<std::string>& words, const vector<int>& sizes)
{
	if (words.size() == 0) error("word_stats(): !Empty vector");

	Stats w_stats;
	int index = std::distance(sizes.begin(), std::max_element(sizes.begin(), sizes.end())); // returns the index of the largest value in the given range
	w_stats.largest = words[index];

	index = std::distance(sizes.begin(), std::min_element(sizes.begin(), sizes.end())); // returns the index of the smallest value in the given range
	w_stats.smallest = words[index];

	// find lexicographically first and last words
	vector<std::string> wclone = words; 
	std::sort(wclone.begin(), wclone.end());
	w_stats.first = wclone.front();
	w_stats.last = wclone.back();

	return w_stats;
}

void print_stats(const vector<std::string>& words, const Stats& s, const std::string& label)
{
	std::cout << label << " {" << '\n';
	std::cout << "  (";
	for (int i = 0; i < words.size() - 1; ++i) { // loop till second last element so that no comma is printed after last element
		std::cout << words[i] << ", ";
	}
	std::cout << words.back();
	std::cout << ")" << '\n';

	std::cout << "  Largest : " << s.largest << '\n';
	std::cout << "  Smallest: " << s.smallest << '\n';
	std::cout << "  First   : " << s.first << '\n';
	std::cout << "  Last    : " << s.last << '\n';
	std::cout << "}" << '\n';
}

int main()
{
	try {
		vector<std::string> test1 = { "hello", "world", "programming", "in", "c++", "is", "fun" };
		Stats test_stats = word_stats(test1, word_sizes(test1));
		print_stats(test1, test_stats, "test_case01");

		vector<std::string> test2;
		test2.push_back("h");
		test2.push_back("h");

		test_stats = word_stats(test2, word_sizes(test2));
		print_stats(test2, test_stats, "test_case02");

		vector<std::string> test3;
		test3.push_back("app");
		test3.push_back("apple");
		test3.push_back("appy");

		test_stats = word_stats(test3, word_sizes(test3));
		print_stats(test3, test_stats, "test_case03");


		return 0;
	}
	catch (runtime_error& err) {
		std::cerr << err.what() << '\n';
		return -1;
	}
	catch (...) {
		std::cerr << "!Unknown exception" << '\n';
		return -2;
	}
}