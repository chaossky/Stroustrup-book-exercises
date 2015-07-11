#include "book.h"

// In the drill, you wrote a program that, given a series of numbers,
// found the max and min of that series.  The number that appears the
// most times in a sequence is called the mode.  Create a program that
// finds the mode of a set of positive integers.

// Exercise 17: Write a program that finds the min, max, and mode of
// a sequence of strings.  I am adapting the solution for Exercise 16
// to solve this one.

int main()
{
	vector<string> strs;
	vector<unsigned int> times;
	string inp;

	// I found two definitions of the mode.  The mode is the one string
	// that occurs most often in a set.  One definition states that if
	// two or more strings tie for most occurrences, those strings are
	// all the mode.  Another definition is that if that happens, there
	// is no mode (the mode can only be one string).  For this program,
	// I will go with the first definition.

	cout << "Enter a sequence of strings, separated by spaces\n"
		<< "or by the ENTER key.  CTRL-D will terminate input.\n";
	cout << "> ";

	bool dupl=false;
	int i;
	string mode, min, max;
	int most=1;

	while(cin>>inp) {
		
		// push_back the string if the vector is empty.
		// This will make it easier to not jam up the other loops.

		if(!(strs.size())) {
			strs.push_back(inp);
			times.push_back(1);
			min=inp;
			max=inp;
			continue;
		}
		
		dupl=false;

		// Keep track of what the mode is as the numbers are entered.

		for(i=0;i<strs.size();i++) {
			if(strs[i]==inp) {
				times[i]++;
				dupl=true;
				if(times[i]>most) {most=times[i]; mode=i;}
				continue;
			}
		}
		if(!dupl) {
			strs.push_back(inp); 
			times.push_back(1);
			min=(inp<min)?inp:min;
			max=(inp>max)?inp:max;
		}
	}

	cout << "Input terminated." << endl;
	cout << "\nThe most occurrences of a string was " << most << endl;
	cout << "The mode is: ";

	// Check first to see if every string in the list occurred the same
	// amount of times, in which case there is no mode.

	dupl=true;
	for(unsigned int t : times)
		if(t!=most) {dupl=false; break;}
	if(dupl&&strs.size()>1) {
		cout << "None.  All entries are equally represented." << endl;
		return 0;
	} else {
		dupl=false;
		for(i=0;i<times.size();i++) {
			if(times[i]==most) {
				if(dupl) {cout << ", ";}
				cout << strs[i];
				dupl=true;
			}
		}
	}

	cout << endl;
	cout << "The minimum string is: " << min << endl;
	cout << "The maximum string is: " << max << endl;

	return 0;
}
