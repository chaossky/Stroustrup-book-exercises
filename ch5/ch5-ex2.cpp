#include "book.h"

// The following program takes in a temperature value in Celsius and
// converts it to Kelvin.  This code has many errors in it.  Find the
// errors, list them, and correct the code.

// 1.  (18) int k should be a double.
// 2.  (19) return should return k.
// 3.  (26) cin should be streaming to c.
// 4.  (27) k should be initialized with ctok(c)
// 5.  (28) cout should not be capitalized.

// Take my word for it, I did the exercise.  Only the correct code will
// be in this file, and if you run it you'll get temperatures in Kelvin.

double ctok(double c)			
{
	double k = c+273.15;
	return k;
}

int main()
{
	double c=0;

	cin >> c;
	double k=ctok(c);
	cout << k << '\n';
}
