#include "book.h"

// Absolute zero is the lowest temperature that can be reached; it is
// -273.15C, or 0K.  The above program, even when corrected, will produce
// erroneous results when given a temperature below this.  Place a
// check in the main program that will produce an error if a temperature
// is given below -273.15C.

double ctok(double c)			
{
	double k = c+273.15;
	return k;
}

int main()
{
	const double MINC=-273.15;
	double c=0;

	cin >> c;
	if(c<MINC) {
		cout << "Temperature is below 0 Kelvin." << endl;
		return 0;
	}
	double k=ctok(c);
	cout << k << '\n';
}
