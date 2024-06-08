#include"std_lib_facilities.h"

int main()
{
	std::string dislike = "broccoli";

	vector<std::string> words;
	for (std::string word; std::cin >> word;) words.push_back(word);

	for (std::string word : words)
	{
		if (word == dislike)
			std::cout << "BLEEP";
		else
			std::cout << word;

		std::cout << " ";
	}
}