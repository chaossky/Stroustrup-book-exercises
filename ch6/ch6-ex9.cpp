#include "book.h"

// Write a program that reads digits and composes them into integers.  For example, 123
// is read as the characters 1, 2, and 3.  The program should output 123 is 1 hundred and
// 2 tens and 3 ones.  The number should be output as an int value.  Handle numbers with
// one, two, three, or four digits.  Hint:  To get the integer value 5 from the character
// '5' subtrace '0', that is, '5'-'0'==5.

// Gee, I could really use pointers right about now...

int main()
{
	vector<string> placenames;
	vector<char> digits;
	vector<int> multiplyby;
	unsigned int number = 0;
	char inp;
	string description;

	const int MAXLEN = 4;

	// Push names for each digit place.

	placenames.push_back("one");
	placenames.push_back("ten");
	placenames.push_back("hundred");
	placenames.push_back("thousand");
	placenames.push_back("TOO BIG");

	// Push multipliers for each digit place.

	multiplyby.push_back(1);
	multiplyby.push_back(10);
	multiplyby.push_back(100);
	multiplyby.push_back(1000);
	multiplyby.push_back(10000);

	// RECEEV INPUT

	cout << "Only the first " << MAXLEN << " digits will be used." << endl;
	cout << "Enter a non-negative number: ";
	while(true) {
		inp=cin.get();
		if(inp=='\n') break;
		if(inp<'0'||inp>'9') {
			cout << "The number must be non-negative." << endl;
			return 1;
		}
		digits.push_back(inp);
		if(digits.size()>MAXLEN-1) break;
	}

	if(digits.size()==0) {
		cout << "You didn't enter a number." << endl;
		return 1;
	}

	// Fill string description.
	
	int tmp = 0;

	for(int i=0;i<digits.size();i++) {
		tmp=digits[i]-'0';		// convert the char into a number.
		number+=tmp*multiplyby[digits.size()-i-1];
		description=description+digits[i]+' '+placenames[digits.size()-i-1];
		if(tmp!=1) description+='s';		// pluralize if not 1
		description+=' ';
		if(digits.size()-i>1) description+="and ";		// add "and" if there's more.
	}

	description.erase(description.end()-1);
	description+=".";		// Otherwise there is a space before the period.

	// Print output.

	cout << number << " is " << description << endl;

	// That's it.

	return 0;
}
