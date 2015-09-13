#include "book.h"

// Exercise 2:  Write a function print() that prints a vector of ints to cout.  Give it two
// arguments:  a string for "labeling" the output and a vector.

void print(string label, vector<int>& nums)
{
	cout << label << ": ";
	for(int i : nums)
		cout << i << "  ";
}
