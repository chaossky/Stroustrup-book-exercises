#include "book.h"

int main()
{
	cout << "Please enter expression (+ and - are good): ";
	int lval=0;
	int rval;
	char op;
	int res;
	cin>>lval>>op>>rval;

	if(op=='+')
		res=lval+rval;
	else if(op=='-')
		res=lval-rval;

	cout << "Result: " << res << endl;
	return 0;
}
