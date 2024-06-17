/*
Modify the calculator program from Chapter 7 to make the input stream an explicit parameter (as shown in §8.5.8),
rather than simply using cin. Also give the Token_stream constructor (§7.8.2) an istream& parameter so that when
we figure out how to make our own istreams (e.g., attached to files), we can use the calculator for those. Hint: Don’t try
to copy an istream.
*/

/*
A simple calculator implemented in C++

	Grammar:
	Calculation:
		Statement Print
		Calculation Statement Print
		Print
		Quit
	Statement:
		Declaration
		Expression
		Assignment
		Print
		Quit
	Quit:
		"quit"
	Print:
		"\n"
		";"
	Declaration:
		"let" Name "=" Expression
		"const" Name "=" Expression
	Assignment:
		Name "=" Expression
	Expression:
		Term
		Term "+" Expression
		Term "-" Expression
	Term:
		Primary
		Term "/" Primary
		Term "*" Primary
		Term "%" Primary
	Primary:
		Number
		Name
		Function "(" Expression ")"
		Function "(" Expression "," Expression ")"
		Name
		"(" Expression ")"
	Number:
		floating-point literal
	Function:
		"sqrt"
		"pow"
	Name:
		string literal
*/

// We would have to add a Token_stream& argument to the following methods:
// expression()
// term()
// primary()
// declare()
// set()

#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
	string name;

	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string n) :kind(ch), name(n) { }
};

class Token_stream {
public:
	Token_stream() { }
	Token_stream(istream& f) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
private:
	bool full = false;
	Token buffer{ 0 };
};

class Variable {
public:
	string name;
	double value;
	char type;
	Variable(string n, double v, char t) :name(n), value(v), type(t) { }
};

class Symbol_table {
public:
	double declare(char type, Token_stream& ts);
	void predefine(string n, double d);
	double set(string& name, Token_stream& ts);
	double get(string s);
	bool is_declared(string s);
private:
	vector<Variable> names;
};

//Keywords chosen arbitrarily
const char let = 'L';
const char assign = 'n';
const char constant = 'c';

const char quit = 'Q';
const char print = '\n';

const char number = '8';
const char name = 'a';

const char sq = 's';
const char expo = 'e';
Symbol_table var;

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin.get(ch);
	switch (ch) {
	case '(':
	case ')':
	case ',':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
		return Token(ch);
	case '\n': case ';':
		return Token(print);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token{number, val};
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;	
			cin.unget();
			if (s == "let") return Token{ let };
			if (s == "const") return Token{ constant };
			if (s == "quit") return Token{ quit };
			if (s == "sqrt") return Token{ sq };
			if (s == "pow") return Token{ expo };
			return Token{ name, s };
		}
		else if (isspace(ch)) {
			// Keep eating whitespace until we
			// find a valid token
			Token t = this->get();
			// The this keyword is a pointer to the object that calls this method
			return t;
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	// Eat all characters present in the line or
	// until a c character is encountered.
	if (full && (buffer.kind == '\n' || buffer.kind == c)) {
		full = false;
		return;
	}

	full = false;
	for (char ch; cin.get(ch);) {
		if (ch == '\n' || ch == c) break;
	}
}

double Symbol_table::get(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get_value: undefined name ", s);
}

void Symbol_table::predefine(string n, double d)
{
	Variable v { n, d, constant };
	names.push_back(v);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double expression(Token_stream& ts);
double sqroot(Token_stream& ts);
double power(Token_stream& ts);

double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')' && t.kind != ',') error("')' expected");
		return d;
	}
	case '-':
		return -primary(ts);
	case '+':
		return primary(ts);
	case number:
		return t.value;
	case name:
		return var.get(t.name);
	case sq:
		return sqroot(ts);
	case expo:
		return power(ts);
	default:
		error("primary expected");
	}
}

double sqroot(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind == '(') {
		ts.unget(t);
		double d = expression(ts);
		if (d < 0) error("sqrt of negative number");
		return sqrt(d);
	}
	error("sqroot missing (");
}

double power(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind == '(') {
		double base = expression(ts);
		t = ts.get();
		if (t.kind != ',') error("power: missing exponential term");
		int exponent = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("power: ')' expected");
		return pow(base, exponent);
	}
	error("power: expected base and exponent");
}

double term(Token_stream& ts)
{
	double left = primary(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{
			double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression(Token_stream& ts)
{
	double left = term(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double Symbol_table::declare(char type, Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != name) 
		error("name expected in declaration");

	string name = t.name;
	if (is_declared(name)) 
		error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", name);

	double d = expression(ts);
	names.push_back(Variable(name, d, type));

	return d;
}

double Symbol_table::set(std::string& name, Token_stream& ts)
{
	if (!is_declared(name)) error(name, " is not defined");
	double d = expression(ts);

	for (Variable& v : names) {
		if (v.name == name){
			if ((v.type) == constant) error("assignment: cannot modify const variable");
			v.value = d;
			break;
		}
	}
	return d;
}

double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return var.declare(let, ts);
	case constant:
		return var.declare(constant, ts);
	case name:
	{
		// Distinguishes a name used in assignment 
	    // from a name used in expression.
		char ch;
		std::cin >> ch;
		if (ch == '=') { 
			return var.set(t.name, ts);
		}
		std::cin.putback(ch);
		// Get input directly using std::cin as Token buffer 
		// can't hold more than one token at a time. This might
		// not be a scalable approach but it will do for now.
	}
	default:
		ts.unget(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	Token_stream ts;

	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement(ts) << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main()

try {
	var.predefine("pi", 3.14);
	var.predefine("e", 2.27);

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}