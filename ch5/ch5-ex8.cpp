#include "book.h"

// Write a program that reads and stores a series of integers and then
// computes the sum of the first N integers.  First ask for N, then
// read the values into a vector, then calculate the sum of the first
// N values.  For example:
// "Please enter the number of values you want to sum:"
// 3
// "Please enter some integers (press '|' to stop):"
// 12 23 13 24 15 |
// 
// The sum of the first 3 numbers (12 23 13) is 48.
//
// Handle all inputs.  For example, make sure to give an error message if
// the user asks for a sum of more numbers than there are in the vector.
//
// Exercise 10: Modify the program from Exercise 8 to use double instead of
// int.  Also, make a vector of doubles containing the N-1 differences
// between adjacent values and write out that vector of differences.

int main()
{
	double inp, sum;
	unsigned int numvalues;
	vector<double> nums;
	vector<double> diffs;

	cout << "Sum of the first N numbers." << endl;
	cout << "Enter an integer value for N: ";
	if(!(cin>>numvalues)||numvalues<1) {
		cout << "That's not a good value for N.  Program over." << endl;
		return 0;
	}

	cout << "N = " << numvalues << endl;

	cout << "Enter some numbers, followed by | to stop" << endl << "> ";
	for(int i=0;;i++) {
		if(!(cin>>inp)) {
			cout << "Input terminated." << endl << endl;
			break;
		}
		nums.push_back(inp);
		if(nums.size()>1)
			diffs.push_back(nums[i]-nums[i-1]);
		if(i<numvalues)
			sum+=inp;
	}
	if(nums.size()<numvalues) {
		cout << "You didn't enter enough integers (you wanted the first "
			<< numvalues << ", \nthere are only " << nums.size()
			<< " in the vector.)" << endl;
		return 0;
	}
	cout << "The sum of the first " << numvalues << " numbers\n( ";
	for(int i=0;i<numvalues;i++)
		cout << nums[i] << " ";
	cout << ")" << endl << "is " << sum << "." << endl;
	cout << "The entire vector is:\n( ";
	for(int i=0;i<nums.size();i++)
		cout << nums[i] << " ";
	cout << ")" << endl;
	cout << "The vector of differences is:\n( ";
	for(int i=0;i<diffs.size();i++)
		cout << diffs[i] << " ";
	cout << ")" << endl;

	return 0;
}
