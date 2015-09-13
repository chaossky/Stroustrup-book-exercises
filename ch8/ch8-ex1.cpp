#include "std_lib_facilities.h"

// Exercise 1:  Modify the calculator program from Chapter 7 to make the input stream
// an explicit parameter (as shown in 8.5.8), rather than simply using cin.  Also give
// the Token_stream constructor (7.8.2) an istream& parameter so that when we figure
// out how to make our own istreams (e.g., attached to files), we can use the calculator
// for those.  Hint:  Don't try to copy an istream.
// -----------
// (NOTE:  Methods in Token_stream are still not generalized to work properly on any
// input stream, for the most part.  You can specify another input stream, though.

// These constants are the character values that go in Token.kind to signify a special
// token.

const char LET = 'L';
const char QUIT = 'Q';
const char PRINT = ';';
const char NUMBER = '8';
const char VAR = 'a';
const char SQRT = 's';
const char HELP = 'h';

// These constants are the string values that correspond to a command, represented in
// Token.kind as one of the above commands.

const string SLET = "#";
const string SQUIT = "quit";
const string SHELP = "help";
const string SSQRT = "sqrt";

// Struct for organizing constants and user-defined variables.

struct Variable {
	string name;
	double value;
	bool is_constant;
	Variable(string n, double v) :name(n), value(v), is_constant(false) { }
	Variable(string n, double v, bool b): name(n), value(v), is_constant(b) { }
};

// Class Symbol_table manipulates and stores user-defined variables.

class Symbol_table {
	vector<Variable> vars;
public:
	void set_value(string s, double d);
	double get_value(string s);
	Symbol_table();
};

// Constructor adds constants to vars[].
// pi = 3.14159
// phi = 1.61803
// e = 2.71828
// k = 1000

Symbol_table::Symbol_table()
{
	vars.push_back(Variable("pi",3.14159,true));
	vars.push_back(Variable("phi",1.61803,true));
	vars.push_back(Variable("e",2.71828,true));
	vars.push_back(Variable("k",1000,true));
}

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch): kind(ch), value(0), name("") {}
	Token(char ch, double val): kind(ch), value(val), name("") {}
	Token(char ch, string str): kind(ch), value(0), name(str) {}
	Token(char ch, double val, string str): kind(ch), value(val), name(str) {}
};

class Token_stream {
	istream& istr;
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0), istr(cin) { }
	Token_stream(istream& s) :full(0), buffer(0), istr(s) { }
	Token get();
	void unget(Token t);
	void sputback(string str);
	void end();
	void ignore(char);
};

// Custom string putback() for Token_stream.

void Token_stream::sputback(string str)
{
	string tmp=str;
	reverse(tmp.begin(),tmp.end());
	for(char c : tmp) {
		istr.putback(c);
	}
}

// A more sophisticated unget() that puts buffer contents back into cin, if the buffer is full.
// This should fix some strangeness with get() going behind ts's back and putting things into
// cin behind the buffer.  Only the ts.unget() ideally should be used, and ts.unget() should
// properly manage cin.  That should help.

void Token_stream::unget(Token t)
{
	if(full) {
		switch(buffer.kind) {
			case SQRT:
				sputback(SSQRT);
				break;
			case LET:
				sputback(SLET);
				break;
			case QUIT:
				sputback(SQUIT);
				break;
			case HELP:
				sputback(SHELP);
			case VAR:
			case NUMBER:
				sputback(buffer.name);
				break;
			default:
				istr.putback(buffer.kind);
				break;
		}
	}
	full=true;
	buffer=t;
}

// end(): purges the stream, and then adds a PRINT character.
// This should help clean up error handling.
// No, if you've typed a bunch of OK input after an error, it won't read it.  But that's
// pretty clean for now.

void Token_stream::end()
{
	istr.ignore(1000000,'\n');
	unget(Token(PRINT));
}

// get(): parses the first character in cin and returns a tokenized version of it.
// If the char is an operator or parenthese, it returns an equivalent token.
// If the char is a . or numeral, it is put back and then converted to a tokenized
// double using the stdlib cin parser.
// If the char is a letter, it is put back and then read as a word into a tokenized string
// using the stdlib cin parser.
// Returns a PRINT symbol upon encountering a newline.

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	while(istr.get(ch),isspace(ch) && ch!='\n') {}
	switch (ch) {
		// Acceptable symbols.
	case '#':
		return Token(LET);
	case '\n':
		return Token(PRINT);
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case '^':
		return Token(ch);
		// Numerals and the decimal point are parsed as a double.
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	istr.unget();
		double val;
		istr >> val;
		// NUMBER tokens will now include a string representation of their value
		// in Token.name, to help out unget().
		return Token(NUMBER,val,to_string(val));
	}
	default:
		if (isalpha(ch) || ch=='_') {
			string s;
			s += ch;

			// Alphanumeric names/commands are parsed until non-alphanumeric
			// input is found.

			while(istr.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;
			istr.unget();
			if (s==SQUIT) return Token(QUIT);
			if (s==SSQRT) return Token(SQRT);
			if (s==SHELP) return Token(HELP);
			return Token(VAR,s);
		}

		end();
		error("Bad token: "+to_string(ch));
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
	while (istr>>ch)
		if (ch==c) return;
}

Token_stream ts;

// Gets the value of an already declared variable, if it exists.

double Symbol_table::get_value(string s)
{
	for (int i = 0; i<vars.size(); ++i)
		if (vars[i].name == s) return vars[i].value;
	ts.end();
	error("get: undefined name ",s);
}

// Sets the value of an already declared variable, if it exists.
// Create a new variable with name s and value d, if it does not.
// Throws an error if the user attempts to assign a value to a constant.

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i<vars.size(); ++i)
		if (vars[i].name == s) {
			if(vars[i].is_constant) {
				string report="set: "+s+" is a constant and cannot be modified.";
				error(report);
			}
			vars[i].value = d;
			return;
		}
	vars.push_back(Variable(s, d));
}

// Symbol_table instance for manipulating user-defined variables.

Symbol_table variables;

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
			error("')' expected");
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
		return variables.get_value(t.name);
	case SQRT:	{
		t=ts.get();
		if(t.kind!='(') {
			ts.end();
			error("sqrt: sqrt must be of the form sqrt(expression)");
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

// This function sets the value of a variable.
// If the declaration has syntax errors, it throws an error.
// Proper declaration is:  # <variable> = <value>;

double declaration()
{
	Token t = ts.get();
	if (t.kind != VAR) {
		ts.end();
		error ("Valid name expected in declaration");
	}
	string name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') {
		ts.end();
		error("'=' missing in declaration of " ,name);
	}
	double d = expression();
	variables.set_value(name, d);
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

void help();

void calculate()
{
	while(true) try {
		cout << PROMPT;
		Token t = ts.get();
		while (t.kind == PRINT) t=ts.get();
		if (t.kind == QUIT) return;
		if (t.kind == HELP) help();
		ts.unget(t);
		cout << RESULT << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

// help():
// Prints out a little help screen with instructions and whatnot.

void help()
{
	cout << endl;
	cout << "CALCULATOR\n"
		<< "----------" << endl
		<< "Acceptable operations: + - * / ^\n"
		<< "+: addition  -: subtraction  *: multiplication  /: division  ^: exponent\n\n"
		<< SLET << " <variable> = <value>: declare/assign a variable with value <value>\n"
		<< "Variable names cannot start with a number, and must consist of letters, numbers,\n"
		<< "or underscores."<<endl
		<< "Example: #g=24; variable g is now equal to 24."<<endl
		<< "#g=g*2; variable g is now equal to 48."<<endl
		<< "#_2cool_4u=4^3-sqrt(64); variable _2cool_4u is now equal to 56."<<endl<<endl
		<< SQUIT << ": exit CALCULATOR\n"
		<< "End a statement with " << PRINT << endl
		<< "CALCULATOR does not appreciate when you type things like: " << PRINT
		<< PRINT << PRINT << PRINT << PRINT << PRINT << PRINT << endl
		<< "---------------" << endl;
}

int main()
{
	// Instructions and whatnot.
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
