#include "book.h"

// Try this:  convert yen, euros, and pounds into American dollars.

int main()
{
	// Exchange rates current as of June 29, 2015.
	const double EURO = 1.12;
	const double YEN = 0.0082;
	const double POUND = 1.57;
	const double YUAN = 0.16;
	const double KRONE = 0.13;

	double amount;

	cout << "Convert foreign currency to American dollars!\n\n";
	cout << "1. Euros to dollars\n" 
		<< "2. British pounds to dollars\n"
		<< "3. Yen to dollars\n"
		<< "4. Yuan to dollars.\n"
		<< "5. Krone to dollars.\n\n";
	int choice=0;
	cout << "Enter your choice (1-5): ";
	cin >> choice;
	cin.ignore(10000,'\n');
	if(choice<1 || choice>5) {
		cout << "Invalid menu choice." << endl;
		return 1;
	}
	cout << "Amount of currency to exchange: ";
	cin >> amount;
	cin.ignore(10000, '\n');
	switch(choice) {
		case 1:
			cout << amount << " euros is " << amount*EURO << " dollars.\n";
			break;
		case 2:
			cout << amount << " pounds is " << amount*POUND << " dollars.\n";
			break;
		case 3:
			cout << amount << " yen is " << amount*YEN << " dollars.\n";
			break;
		case 4:
			cout << amount << " yuan is " << amount*YUAN << " dollars.\n";
			break;
		case 5:
			cout << amount << " krone is " << amount*KRONE << " dollars.\n";
			break;
		default:
			break;
	}

	return 0;
}
	
