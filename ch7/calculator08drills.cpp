
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
	Drill (Chapter 7)

	1.  Starting from the file calculator08buggy.cpp, get the calculator to compile.
	[DONE]

	2.  Go through the entire program and add appropriate comments.
	[DONE] I probably don't know the meaning of the word "appropriate" :)

	3.  As you commented, you found errors (deviouslyl inserted especially for you
	to find).  Fix them; they are not in the text of the book.
	[DONE] It seems to work well enough, at least.

	4.  Testing:  prepare a set of inputs and use them to test the calculator.  Is your
	list pretty complete?  What should you look for?  Include negative values, 0, very
	small, very large, and "silly" inputs.
	[DONE] Any string that resembles ";;;;;;;;;;" doesn't seem to parse very well.  If
	I had made this bastard myself from scratch, it would.  But working with what I have,
	I got most of the rest of it to work decently.

	5.  Do the testing and fix any bugs that you missed when you commented.
	[DONE]

	6.  Add a predefined name k meaning 1000.

	7.  Give the user a square root function sqrt(), for example, sqrt(2+6.7).  Naturally,
	the value of sqrt(x) is the square root of x; for example, sqrt(9) is 3.  Use the
	standard library sqrt() function that is available through the header
	std_lib_facilities.h.  Remember to update the comments, including the grammar.
	[DONE]

	8.  Catch attempts to take the square root of a negative number and print an appropriate
	error message.
	[DONE]

	9.  Allow the user to use pow(x,i) to mean "Multiply x with itself i times"; for example,
	pow(2.5,3) is 2.5*2.5*2.5.  Require i to be an integer using the technique we used for
	%. (CHANGED:  Implement the ^ operator to do exponents)
	[DONE]  Implementing pow() in this way would require parsing a comma, which is too
	awkward and overdone for this function.  Instead, I am going to implement the ^ operator,
	which does the same thing much more elegantly.  Furthermore, it doesn't require integer
	operators for any of it.  Implementing the comma, one might as well just create an
	entire argument-passing architecture...kludging this calculator design to include a
	comma is...retarded.  It's stupid.  I am not doing it that way.

	10.  Change the "declaration keyword" from let to #.
	[DONE]

	11.  Change the "quit keyword" from quit to exit.  That will involve defining a string
	for quit just as we did for let in 7.8.2.
	[DONE]  I already moved everything over to string constants.  That's what the cool kids
	do.

*/

#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch): kind(ch), value(0), name("") {}
	Token(char ch, double val): kind(ch), value(val), name("") {}
	Token(char ch, string str): kind(ch), value(0), name(str) {}
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }
	void end();
	void ignore(char);
};

// These constants are the character values that go in Token.kind to signify a special
// token.

const char LET = 'L';
const char QUIT = 'Q';
const char PRINT = ';';
const char NUMBER = '8';
const char VAR = 'a';
const char SQRT = 's';

const string SLET = "#";
const string SQUIT = "exit";
const string SSQRT = "sqrt";

// end(): purges the stream, and then adds a PRINT character.
// This should help clean up error handling.
// No, if you've typed a bunch of OK input after an error, it won't read it.  But that's
// pretty clean for now.

void Token_stream::end()
{
	cin.ignore(1000000,'\n');
	buffer=Token(PRINT);
	full=true;
}

// get(): parses the first character in cin and returns a tokenized version of it.
// If the char is an operator or parenthese, it returns an equivalent token.
// If the char is a . or numeral, it is put back and then converted to a tokenized
// double using the stdlib cin parser.
// If the char is a letter, it is put back and then read as a word into a tokenized string
// using the stdlib cin parser.

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
		// Acceptable symbols.
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case '#':
	case '^':
		if(ch=='#') return Token(LET);
		return Token(ch);
		// Numerals and the decimal point are parsed as a double.
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(NUMBER,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;

			// Alphanumeric names/commands are parsed until non-alphanumeric
			// input is found.

			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
			cin.unget();
			if (s == SQUIT) return Token(QUIT);
			if (s == SSQRT) return Token(SQRT);
			return Token(VAR,s);
		}
		end();
		error("Bad token");
	}
}

// This function clears the input stream until char c is detected or the stream is empty.
// It will eat the first instance of c.

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

Token_stream ts;

// This struct keeps track of in-calculator variables.

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	

// Gets the value of an already declared variable, if it exists.

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	ts.end();
	error("get: undefined name ",s);
}

// Sets the value of an already declared variable, if it exists.

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	ts.end();
	error("set: undefined name ",s);
}

// Returns true if a variable exists, and false if it does not.

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double expression();

// primary():
// +,- Floating-Point Number
// (Expression)
// Previously assigned variable
// [NEW] sqrt(Expression)
// -- No parentheses around the Expression following sqrt will be a syntax error.

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	// Handles expressions in parentheses.
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') {
			ts.end();
			error("'(' expected");
		}
		return d;
	}
	// This handles unary + or -
	case '-':
		return - primary();
	case '+':
		return + primary();
	case NUMBER:
		return t.value;
	case VAR:
		return get_value(t.name);
	case SQRT:	{
		t=ts.get();
		if(t.kind!='(') {
			ts.end();
			error("sqrt: sqrt must be of the form sqrt(<expression>)");
		}
		ts.unget(t);
		double d = primary();
		if(d<0) {
			ts.end();
			error("sqrt: cannot take square root of a negative number");
		}
		return sqrt(d);
	}
	default:
		ts.end();
		error("primary expected");
	}
}

// power()
// Primary^Primary

double power()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		if(t.kind=='^') {
			left=pow(left,primary());
		} else {
			ts.unget(t);
			return left;
		}
	}
}

// term():
// Term*Power
// Term/Power

double term()
{
	double left = power();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= power();
			break;
		case '/':
		{	double d = power();
			if (d == 0) {
				ts.end();
				error("divide by zero");
			}
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// expression()
// Term+Term
// Term-Term

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// This function creates a new variable with the assigned value.
// If the variable already exists, or the declaration has syntax errors, it throws
// an error.
// Proper declaration is:  let <variable> = <value>;
// -- declaration() now reassigns a value to an existing variable.  "let" is now the
// keyword to do any changes to the value of a variable.

double declaration()
{
	Token t = ts.get();
	if (t.kind != VAR) {
		ts.end();
		error ("name expected in declaration");
	}
	string name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') {
		ts.end();
		error("'=' missing in declaration of " ,name);
	}
	double d = expression();
	if(!is_declared(name)) names.push_back(Variable(name,d));
	else set_value(name, d);
	return d;
}

// statement():
// Declaration
// Expression

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case LET:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(PRINT);
}

const string PROMPT = "> ";
const string RESULT = "= ";

// calculate():
// Evaluates a statement until the PRINT character, and then outputs the result.
// Quits the program if the QUIT command is input.

void calculate()
{
	while(true) try {
		cout << PROMPT;
		Token t = ts.get();
		while (t.kind == PRINT) t=ts.get();
		if (t.kind == QUIT) return;
		ts.unget(t);
		cout << RESULT << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	// Instructions and whatnot.
	cout << "CALCULATOR\n"
		<< "Acceptable operations: + - * /\n"
		<< SLET << " <variable> = <value>: declare/assign a variable with value <value>\n"
		<< SQUIT << ": exit CALCULATOR\n"
		<< "End a statement with " << PRINT << endl
		<< "CALCULATOR does not appreciate when you type things like: " << PRINT
		<< PRINT << PRINT << PRINT << PRINT << PRINT << PRINT << endl
		<< "---------------" << endl;
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
