#include "book.h"

// Write a program that converts from Celsius to Fahrenheit and vice
// versa.  Use estimation to see if your results are plausible.

int main()
{
	double intemp, outtemp;
	int inp=0;

	cout << "Fahrenheit/Celsius converter" << endl;
	cout << "1. Enter Fahrenheit/Convert to Celsius" << endl
		<< "2. Enter Celsius/Convert to Fahrenheit" << endl;

	while(inp<1||inp>2) {
		cout << "> ";
		if(!(cin>>inp)) {
			cout << "Invalid input. Terminating program." << endl;
			return 0;
		}
	}
	
	string fc=(inp==1)?"Fahrenheit":"Celsius";
	cout << "Enter temperature in " << fc << ": ";
	if(!(cin>>intemp)) {
		cout << "Invalid temperature.  Terminating program." << endl;
		return 0;
	}
	cout << "You entered " << intemp << " degrees." << endl;
	cout << intemp << " degrees " << fc << " is ";
	switch(inp) {
		case 1:
			outtemp=(intemp-32)*(5.0/9);
			break;
		case 2:
			outtemp=1.8*intemp+32;
			break;
		default:
			cout << "fnord" << endl;
			break;
	}
	cout << outtemp << " degrees "
		<< ((inp==1)?"Celsius.\n":"Fahrenheit.\n");
	return 0;
}
