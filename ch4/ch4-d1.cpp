#include "book.h"
#include <float.h>
#include <algorithm>

// Write a program that consists of a while-loop that (each time around
// the loop) reads in two ints and then prints them.  Exit the program
// when a terminating '|' is entered.  [COMPLETE]
//
// Drill 2: change the program to write out 'the smaller value is: '
// followed by the smaller of the numbers and 'the larger value is: '
// followed by the larger value.  [COMPLETE]
//
// Drill 3: Augment the program so that it writes the line 'the numbers
// are equal' (only) if they are equal.  [COMPLETE]
//
// Drill 4: Change the program so that it uses doubles instead of ints.
// [COMPLETE]
//
// Drill 5: Change the program so that it writes out 'the numbers are
// almost equal' after writing out which is the larger and the smaller
// if the two numbers differ by less than .01.  [COMPLETE]
//
// Drill 6: Now change the body of the loop so that it reads just one
// double each time around.  Define two variables to keep track of which
// is the smallest and which is the largest value you have seen so far.
// Each time through the loop write out the value entered.  If it's the
// smallest so far, write 'the smallest so far' after the number.  If
// it's the largest so far, write 'the largest so far' after the number.
// [COMPLETE]
//
// Drill 7: Add a unit to each double entered; that is, enter values such
// as 10cm, 2.5in, 5ft, or 3.33m.  Accept the four units: cm, m, in, ft.
// Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in.
// Read the unit indicator into a string.  You may consider 12 m (with
// a space between the number and the unit) equivalent to 12m (without
// a space).  [COMPLETE]
//
// Drill 8: Reject values without units or with "illegal" representations
// of units, such as y, yard, meter, km, and gallons. [COMPLETE]
//
// Drill 9: Keep track of the sum of values entered (as well as the
// smallest and largest) and the number of values entered.  When the
// loop ends, print the smallest, the largest, the number of values,
// and the sum of values.  Note that to keep the sum, you have to
// decide on a unit to use for that sum; use meters.  [COMPLETE]
//
// Drill 10: Keep all the values entered (converted into meters) in a
// vector.  At the end, write out those values.  [COMPLETE]
//
// Drill 11: Before writing out the values from the vector, sort them
// (that'll make them come out in increasing order).  [COMPLETE]
//
//**********
//DRILLED.
//**********


int main()
{
	double smallest=DBL_MAX;
	double largest=DBL_MIN;
	double inp;
	double convinp=0;
	double sum=0;
	int numvalues=0;
	string unit;
	vector<string> suffix;
	vector<double> conv;
	vector<double> mvalues;

	// because my silly ass compiler won't initialize a vector with a list
	// yet.

	suffix.push_back("cm");
	suffix.push_back("ft");
	suffix.push_back("in");
	suffix.push_back("m");

	// Conversion to meters for the suffixes (multiply by)

	conv.push_back(0.01);
	conv.push_back(0.3048);
	conv.push_back(0.0254);
	conv.push_back(1);
	
	while(cin>>inp>>unit) {
		cout << inp;
		if(inp<smallest) {
			smallest=inp;
			cout << " -- smallest number so far";
		}
		if(inp>largest) {
			largest=inp;
			cout << " -- largest number so far";
		}
		cout << endl << endl << "Suffix is: " << unit;
		cout << ". ";
		bool isgood = false;
		int i=0;
		for(;i<suffix.size();i++) {
			if(unit==suffix[i]) {isgood=true; convinp=inp*conv[i]; break;}
		}
		convinp=(isgood)?convinp:0;
		numvalues+=(isgood)?1:0;
		if(isgood) mvalues.push_back(convinp);
		sum+=convinp;
		cout << ((isgood)?"It's a good suffix.\n":"It's not a valid suffix.\n");
		cout << "The length is " << convinp << " meters." << endl;
	}

	cout << "Terminated by non-numeral input." << endl;
	cout << "Sum of all lengths so far: " << sum << " meters." << endl;
	cout << numvalues << " valid measurements entered in total." << endl;
	cout << "Smallest number: " << smallest << endl;
	cout << "Largest number: " << largest << endl;
	cout << endl << "Lengths entered (in meters): ";
	sort(mvalues.begin(),mvalues.end());
	for(double d : mvalues)
		cout << d << " ";
	cout << endl;

	return 0;
}
