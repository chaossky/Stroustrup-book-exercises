#include "book.h"

// Try out this vector thingy a bit.

int main()
{
	vector<double> temps;
	
	// That's how you work a for loop.

	for(double temp; temps.size()<10; (cin >> temp,temps.push_back(temp)))
		cout << 10-temps.size() << " values left.  Enter a number: ";

	cout << endl;
	for(double d : temps)
		cout << d << "  ";
	
	return 0;
}
