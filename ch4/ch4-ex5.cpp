#include "book.h"

// Write a program that performs as a very simple calculator.  Your
// calculator should be able to handle the four basic math operations --
// add, subtract, multiply, and divide -- on two input values.  Your
// program should prompt the user to enter three arguments: two double
// values and a character to represent an operation.  If the entry
// arguments are 35.6, 24.1, and +, the program output should be
// The sum of 35.6 and 24.1 is 59.7.  In Chapter 6 we look at a much
// more sophisticated simple calculator.

int main()
{
	double val1, val2, result;
	char op;
	bool opgood;
	string opname="";

	// Intro & instructions

	cout << "Simple calculator:" << endl
		<< "(value1) (value2) (operand)" << endl
		<< "Ex: 35 7 / is 5, 4 8 + is 12, 6 9 - is -3." << endl
		<< "Valid operands are: + - * /" << endl
		<< "---------------------------" << endl;

	// If input loop fails in any way, program quits with error.

	cout << "> ";
	while(cin >> val1 >> val2 >> op) {
		opgood=true;
		switch(op) {
			case '+':
				result=val1+val2;
				opname="sum";
				break;
			case '-':
				result=val1-val2;
				opname="difference";
				break;
			case '*':
				result=val1*val2;
				opname="product";
				break;
			case '/':
				result=val1/val2;
				opname="quotient";
				break;
			default:
				opgood=false;
				break;
		}
		if(!opgood) {
			cout << "ERROR:  The operand is invalid." << endl;
			break;
		}
		cout << "The " << opname << " of " << val1 << " and " << val2
			<< " is " << result << endl;
		cout << "> ";
	}

	cout << "Program terminated from bad input." << endl;

	return 0;
}
