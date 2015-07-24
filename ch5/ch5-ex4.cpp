#include "book.h"

// Do exercise 3 again, but this time handle the error inside ctok().

// Exercise 5: Add to the program so that it can also convert from Kelvin
// to Celsius.

double ctok(double c)			
{
	double k = c+273.15;
	if(k<0) {
		cout << "ctok: temperature is below absolute zero." << endl;
		return 0;
	}
	return k;
}

double ktoc(double k)
{
	if(k<0) {
		cout << "ktoc: temperature is below absolute zero." << endl;
		return -273.15;
	}
	double c=k-273.15;
	return c;
}

int main()
{
	double c=0;
	int sel;

	cout << "Celsius-Kelvin conversion" << endl;
	cout << "1. Celsius to Kelvin" << endl
		<< "2. Kelvin to Celsius" << endl;
	bool good=false;
	while(!good) {
		cout << "Enter your selection: ";
		if(!(cin>>sel)) {
			cout << "Invalid input." << endl;
			return 0;
		}
		if(!(sel<1||sel>2)) good=true;
	}

	cout << "Selection was " << sel << "." << endl;
	cout << "Enter temperature to convert: ";
	if(!(cin>>c)) {
		cout << "Invalid input." << endl;
		return 0;
	}
	double t;
	switch(sel) {
		case 1:
			t=ctok(c);
			cout << c << " degrees Celsius is " << t << " degrees Kelvin." << endl;
			break;
		case 2:
			t=ktoc(c);
			cout << c << " degrees Kelvin is " << t << " degrees Celsius." << endl;
			break;
		default:
			cout << "I have no idea what happened." << endl;
			break;
	}

	return 0;
}
