#include "book.h"

// Exercise 2:  Add the ability to use {} as well as () in the program, so that
// {(4+5)*6}/(3+4) will be a valid expression.

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
	case '{': case '}':
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
			return e;
		}
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
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

