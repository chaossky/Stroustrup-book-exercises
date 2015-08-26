#include "book.h"

// Add a factorial operator: use a suffix ! operator to represent "factorial".
// For example, the expression 7! means 7*6*5*4*3*2*1,  Make ! bind tighter than * and /;
// that is, 7*8! means 7*(8!) rather than (7*8)!.  Begin by modifying the grammar to
// account for a higher-level operator.  To agree with the standard mathematical definition
// of factorial, let 0! evaluate to 1.  Hint:  The calculator functions deal with doubles,
// but factorial is only defined for ints, so just for x!, assign the x to an int and
// calculate the factorial of that int.

const char END = '=';
const char QUIT = 'x';

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
		return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case END:    // for "print"
    case QUIT:    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
	case '{': case '}': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

Token_stream ts;        // provides get() and putback() 


double expression();    // declaration so that primary() can call expression()

// check for a suffix after an expression (so far, only factorial) and evaluate.
double suffix(double expression)
{
	Token t=ts.get();
	switch(t.kind) {
		case '!':			// factorial (non-recursive algorithm)
		{
			int intexpr=(int)expression;
			if(intexpr<0) error("cannot take the factorial of a negative number");
			if(intexpr<2) return 1;
			int fact=intexpr;
			for(int i=intexpr;i>1;fact*=--i);		// FORE
			return fact;
		}
		default:
			ts.putback(t);
			return expression;
	}
}
// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
	case '{':
		{
			double e=expression();
			t=ts.get();
			if(t.kind!='}') error("'}' expected");
			return suffix(e);
		}
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return suffix(d);
        }
    case '8':            // we use '8' to represent a number
        return suffix(t.value);  // return the number's value
	case END:
	case QUIT:
		ts.putback(t);
		return 0;
    default:
		ts.putback(t);
        error("primary expected");
		return t.value;
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream
    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
			break;
        case '/':
			{
            	double d = primary();
            	if (d == 0) {error("divide by zero"); return t.value;}
            	left /= d; 
            	t = ts.get();
            	break;
			}
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

int main()
try
{
	double val=0;

	cout << "Welcome to our simple calculator." << endl;
	cout << "Please enter expressions using floating-point numbers." << endl;
	cout << "Valid operators: { } ( ) + - * /" << endl;
	cout << "Use "<<END<<" to end an expression.  Type "<<QUIT<<" by itself to quit.\n\n";

    while (cin) {
		val = expression();

        Token t = ts.get();

        if (t.kind == QUIT) break; // 'q' for quit
        if (t.kind == END)        // ';' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
    }
}
catch (exception& e) {
    cout << "error: " << e.what() << '\n'; 
    return 8;
}
catch (...) {
    cout << "Oops: unknown exception!\n"; 
    return 2;
}

