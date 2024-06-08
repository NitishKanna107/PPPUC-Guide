#include "std_lib_facilities.h"

int main() {
	std::string firstName;
	int age = 0;
	
	std::cout << "Enter the name of the person you want to write to: ";
	std::cin >> firstName;
	std::cout << "Enter the age of the recipient: ";
	std::cin >> age;

	if (age <= 0 or age >= 110) {
		simple_error("you're kidding!");
	}
	
	std::string friendName;
	char friendSex = 0;

	std::cout << "Enter the name of your friend: ";
	std::cin >> friendName;
	std::cout << "m if your friend is a male or f if your friend is a female: ";
	std::cin >> friendSex;

	std::cout << "\n";

	std::cout << "Dear " << firstName << ", \n";
	std::cout << "\tHow are you? I am fine. I miss you. If you see " << friendName << " please ask ";
	
	if (friendSex == 'm') {
		std::cout << "him to call me.";
	}
	else if (friendSex == 'f') {
		std::cout << "her to call me.";
	}

	std::cout << " I hear you just had your birthday and you are " << age << " years old.\n";
	std::cout << "Thanking You.\nYours lovingly,\nNitish\n";
}