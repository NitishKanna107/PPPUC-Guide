/*
Create three files: my.h, my.cpp, and use.cpp. The header file my.h contains
extern int foo;
void print_foo();
void print(int);

The source code file my.cpp #includes my.h and std_lib_facilities.h, defines print_foo() to print the value of foo
using cout, and print(int i) to print the value of i using cout.

The source code file use.cpp #includes my.h, defines main() to set the value of foo to 7 and print it using
print_foo(), and to print the value of 99 using print(). Note that use.cpp does not #include std_lib_facilities.h as
it doesn’t directly use any of those facilities.

Get these files compiled and run. On Windows, you need to have both use.cpp and my.cpp in a project and use {
char cc; cin>>cc; } in use.cpp to be able to see your output. Hint: You need to #include <iostream> to use cin.

Comment:
I am not exactly sure why Stroustrup asks Windows users to use { char cc; cin >> cc; } to see the output. In my case I am able to see the output without
adding that line of code in use.cpp. It might be because Visual Studio does something to make it work.
*/

#include"my.h"

//Define foo
int foo;

int main()
{
	//I would like to point out that foo = 7 is not a definition but 
	//an assignment. If you had assumed it to be a way of defining foo and proceeded to
	//compile you must have gotten a linker error.
	foo = 7;
	print_foo();
	print(99);
}
