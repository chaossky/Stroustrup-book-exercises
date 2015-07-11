#include "book.h"

// In the drill, you wrote a program that, given a series of numbers,
// found the max and min of that series.  The number that appears the
// most times in a sequence is called the mode.  Create a program that
// finds the mode of a set of positive integers.

int main()
{
	vector<unsigned int> nums;
	vector<unsigned int> times;
	unsigned int inp;

	// I found two definitions of the mode.  The mode is the one number
	// that occurs most often in a set.  One definition states that if
	// two or more numbers tie for most occurrences, those numbers are
	// all the mode.  Another definition is that if that happens, there
	// is no mode (the mode can only be one number).  For this program,
	// I will go with the first definition.

	cout << "Enter a sequence of positive integers, separated by spaces\n"
		<< "or by the ENTER key.  An invalid entry will terminate input.\n";
	cout << "> ";

	bool dupl=false;
	int i, mode;
	int most=1;

	while(cin>>inp) {
		
		// push_back the number if the vector is empty.
		// This will make it easier to not jam up the other loops.

		if(!(nums.size())) {
			nums.push_back(inp);
			times.push_back(1);
			continue;
		}
		
		dupl=false;

		// Keep track of what the mode is as the numbers are entered.

		for(i=0;i<nums.size();i++) {
			if(nums[i]==inp) {
				times[i]++;
				dupl=true;
				if(times[i]>most) {most=times[i]; mode=i;}
				continue;
			}
		}
		if(!dupl) {nums.push_back(inp); times.push_back(1);}
	}

	cout << "Input terminated." << endl;
	cout << "\nThe most occurrences of a number was " << most << endl;
	cout << "The mode is: ";

	// Check first to see if every number in the list occurred the same
	// amount of times, in which case there is no mode.

	dupl=true;
	for(unsigned int t : times)
		if(t!=most) {dupl=false; break;}
	if(dupl&&nums.size()>1) {
		cout << "None.  All entries are equally represented." << endl;
		return 0;
	}
	dupl=false;
	for(i=0;i<times.size();i++) {
		if(times[i]==most) {
			if(dupl) {cout << ", ";}
			cout << nums[i];
			dupl=true;
		}
	}
			
	return 0;
}
