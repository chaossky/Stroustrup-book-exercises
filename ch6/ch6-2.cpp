#include "book.h"

int main()
{
	cout << "Please enter expression (+,-,*,/ are good)" << endl
		<< "= ends expression (1+2*3=): ";
	int lval=0;
	int rval;
	cin>>lval;
	if(!cin) {
		cout << "ERROR: No first operand" << endl;
		return 0;
	}

	for(char op; cin>>op;) {
		if(op!='=') cin>>rval;
		if(!cin) {
			cout << "ERROR: No second operand" << endl;
			return 0;
		}
		switch(op) {
			case '+':
				lval+=rval;
				break;
			case '-':
				lval-=rval;
				break;
			case '*':
				lval*=rval;
				break;
			case '/':
				lval/=rval;
				break;
			case '=':
				cout << "Result: " << lval << endl;
				return 0;
			default:
				cout << "ERROR: Invalid operand '"<<op<<"'"<<endl;
				return 0;
		}
	}
	cout << "I don't know what happened, dude." << endl;
	return 0;
}
