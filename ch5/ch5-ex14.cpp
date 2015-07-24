#include "book.h"

// Read (day-of-the-week,value) pairs from standard input.  For example:
// Tuesday 23 Friday 56 Tuesday -3 Thursday 99
//
// Collect all the values for each day of the week in a vector<int>.
// Write out the values of the seven day-of-the-week vectors.  Print
// out the sum of the values in each vector.  Ignore illegal days
// of the week, such as Funday (NOTE: It may be illegal but we all
// love Funday.), but accept common synonyms such as Mon and monday.
// Write out the number of rejected values.

int main()
{
	vector<int> daytotals={0,0,0,0,0,0,0};
	vector<string> names= { "sun","Sun","sunday","Sunday", 
							"mon","Mon","monday","Monday",
							"tues","Tues","tuesday","Tuesday",
							"wed","Wed","wednesday","Wednesday",
							"thurs","Thurs","thursday","Thursday",
							"fri","Fri","friday","Friday",
							"sat","Sat","saturday","Saturday"};

	// Seriously, we'd better start learning some string
	// manipulation real quick because this is ridiculous...

	vector<int> nvals=    { 0,0,0,0,
							1,1,1,1,
							2,2,2,2,
							3,3,3,3,
							4,4,4,4,
							5,5,5,5,
							6,6,6,6, };

	int inpi, rejected;
	string inps;

	cout << "Numbers and days of the week and...whatever." << endl
		<< "Enter a day of the week followed by an integer." << endl
		<< "mon 23 Tues -4 wednesday 8 Thursday 9485, etc." << endl
		<< "An invalid day of the week will be tallied as" << endl
		<< "<REJECTED> at the end." << endl
		<< "An invalid integer will end input, and the totals will" << endl
		<< "then be counted." << endl << endl;
	cout << "> ";

	rejected=0;
	bool funday=false;
	while(cin>>inps>>inpi) {
		bool fits=false;
		for(int i=0;i<names.size();i++) {
			if(inps==names[i]) {
				daytotals[nvals[i]]+=inpi;
				fits=true;
				break;
			}
		}
		if(!fits) rejected++;
		if(inps=="funday"||inps=="Funday"||inps=="fun"||inps=="Fun")
			funday=true;
	}
	cout << "END: Bad number input." << endl;
	if(funday) {
		cout << "Funday is any day of the week, "
			<< "if you have a good attitude.\n";
	}
	cout << "TOTALS\n" << "------\n";
	for(int i=0;i<daytotals.size();i++)
		cout << names[i*4+3] << ": " << daytotals[i] << endl;
	cout << "------\n";
	cout << "<REJECTED>: " << rejected;
	cout << endl << "Have a blessed day." << endl;
	return 0;
}
