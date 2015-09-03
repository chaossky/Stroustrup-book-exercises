
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
	Drill (Chapter 7)

	All drills completed as shown in comments of calculator08drills.cpp.
*/

/*
	Exercises (Chapter 7)

	1. Allow underscores in the calculator's variable names. [DONE]

	2. Provide an assignment operator, =, so that you can change the value of a variable
	after you introduce it using let.  Discuss why that can be useful and how it can
	be a source of problems. [DONE, in drills]

	(Explanation:  I reworked the let symbol to assign a new value to a pre-existing
	variable.  This is easier to implement, and safer, because it forces the user
	to be clear about variable assignment, and allows the calculator to naturally
	parse variable expressions with little fuss.  #g=g+1; will increment variable g
	just like a "real" programming language.)

	3. Provide named constants that you really can't change the value of.  Hint:
	You have to add a member to Variable that distinguishes between constants and
	variables and check for it in set_value().  If you want to let the user define
	constants (rather than just having pi and e defined as constants), you'll have
	to add a notation to let the user express that, for example, const pi = 3.14;.

	4. The get_value(), set_value(), is_declared(), and define_name() functions all
	operate on the variable var_table.  Define a class called Symbol_table with a
	member var_table of type vector<Variable> and member functions get(), set(),
	is_declared(), and declare().  Rewrite the calculator to use a variable of type
	Symbol_table. [DONE]

	5. Modify Token_stream::get() to return Token(print) when it sees a newline.
	This implies looking for whitespace characters and treating newline ('\n')
	specially.  You might find the standard library function isspace(ch), which
	returns true if ch is a whitespace character, useful. [DONE]

	6. Part of what every program should do is to provide some way of helping its
	user.  Have the calculator print out some instructions for how to use the calculator
	if the user presses the H key (both upper- and lowercase).  [DONE]

	7. Change the q and h commands to be quit and help, respectively.  [DONE]

	9. Suggest three improvements (not mentioned in this chapter) to the calculator.
	Implement one of them.
	
	- Completely restructure this program to use a more sane paradigm.  If there were
	no object-oriented coding, I would be at least using function pointers and an array
	to keep track of commands and tokens, and have a more generalized Token_stream::get().
	Also, I would alter the code to use any istream, as opposed to being hardcoded for cin,
	so that reading from or writing to a file would be easy as pie.  Also, I would add
	a buffer, possibly in the Token_stream, that would split the main input stream into
	statements by PRINT, and then execute each statement as a piece.  Not only could you
	include easier error-checking this way, but it would get around this clumsy hackjob
	way of dealing with the ; symbol.  I see where this is going, though, eventually
	it would turn into a LISP interpreter.

	- In any case, working on this code any further is becoming a nightmare using only
	the tools that have been presented so far.  This calculator can only improve by learning
	new OOP or pointer techniques, which haven't been learned yet.  Anything I would add
	at this point would make it worse and more nightmarish, so I won't do any more work
	on it.

	- The feature that I would actually implement, which seems somewhat reasonable, would
	be possibly a repeat functionality like regular calculators have.  I made an
	"old-school" calculator that worked like an actual calculator instead of a pseudo-
	interpreter, which is what this is, and the repeat function was easy.  The easiest
	way to do this would be to have either a REPEAT command, to code the <up arrow> key
	to cough up the last thing typed in, or possibly to have lone instances of the
	[PRINT] token execute the last statement.  It seems a reasonable thing to add,
	but not in this codebase.  It's awful right now, and I am tired of hacking away at it.
	So I'm not doing it, sorry.  I hope the rest of my work has been satisfactory.

*/

#include "std_lib_facilities.h"

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

// [NEW] Class Symbol_table manipulates and stores user-defined variables.
// I removed is_declared because...you don't need it.  get_value() handles
// any needed checking for the existence of a variable.

class Symbol_table {
	vector<Variable> vars;
public:
	void set_value(string s, double d);
	double get_value(string s);
	Symbol_table();
};

// Constructor adds constants to vars[].
// Constants are:
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
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

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
		cin.putback(c);
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
				cin.putback(buffer.kind);
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
	cin.ignore(1000000,'\n');
	unget(Token(PRINT));
}

// get(): parses the first character in cin and returns a tokenized version of it.
// If the char is an operator or parenthese, it returns an equivalent token.
// If the char is a . or numeral, it is put back and then converted to a tokenized
// double using the stdlib cin parser.
// If the char is a letter, it is put back and then read as a word into a tokenized string
// using the stdlib cin parser.
// [NEW] Returns a PRINT symbol upon encountering a newline.

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	while(cin.get(ch),isspace(ch) && ch!='\n') {}
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
	{	cin.unget();
		double val;
		cin >> val;
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

			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch;
			cin.unget();
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
	while (cin>>ch)
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
// [NEW] Create a new variable with name s and value d, if it does not.
// [NEW] Throws an error if the user attempts to assign a value to a constant.

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
// [NEW] declaration() now reassigns a value to an existing variable.  # is now the
// keyword to do any changes to the value of a variable.

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
