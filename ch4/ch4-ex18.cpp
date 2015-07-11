#include "book.h"

// Write a program to solve quadratic equations.  A quadratic equation is
// of the form ax^2+bx+c=0.  If you don't know the quadratic formula for
// solving such an expression, do some research.  Remember, researching
// how to solve a problem is often necessary before a programmer can
// teach the computer how to solve it.  Use doubles for the user inputs
// for a, b, and c.  Since there are two solutions to a quadratic equation,
// output both x1 and x2.

int main()
{
	double a, b, c;
	double x1,x2;
	double thingy;		// It has a mathematical name but I forgot it.
	bool imaginary;
	
	cout << "Quadratic equation solver\n"
		<< "The equation takes the form ax^2+bx+c=0.\n";
	
	cout << "Input value for a: ";
	if(!(cin>>a)) {
		cout << "Invalid input.  Terminating program.";
		return 0;
	}
	cout << "Input value for b: ";
	if(!(cin>>b)) {
		cout << "Invalid input.  Terminating program.";
		return 0;
	}
	cout << "Input value for c: ";
	if(!(cin>>c)) {
		cout << "Invalid input.  Terminating program.";
		return 0;
	}

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	// x=(-b+sqrt(b^2-4ac))/2a

	thingy=(b*b)-(4*a*c);
	imaginary=(thingy<0)?true:false;
	thingy=(imaginary)?sqrt(-thingy):sqrt(thingy);
	cout << "thingy is: " << thingy << ((imaginary)?"i":"") << endl;

	if(imaginary) {
		cout << "Answer 1: x=" << -b/(a*2) << "+" << thingy/(a*2) << "i" << endl;
		cout << "Answer 2: x=" << -b/(a*2) << "-" << thingy/(a*2) << "i" << endl;
		return 0;
	}

	cout << "Answer 1: x=" << ((-b)+thingy)/(a*2) << endl;
	cout << "Answer 2: x=" << ((-b)-thingy)/(a*2) << endl;

	return 0;
}
