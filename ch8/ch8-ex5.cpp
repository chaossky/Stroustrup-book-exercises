#include "book.h"

// Exercise 5:  Write two functions that reverse the order of elements in a vector<int>.
// For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.  The first reverse function should
// produce a new vector with the reversed sequence, leaving its original vector unchanged.
// The other reverse function should reverse the elements of its vector without using
// any other vectors (hint: swap).

void first_reverse(vector<int>& source, vector<int>& target)
{
	target.clear();

	for(int i=source.size()-1;i>=0;i--)
		target.push_back(source[i]);
}

void swap_reverse(vector<int>& source)
{
	int first=0;
	int second=source.size()-1;

	while(first<=second) {
		swap(source[first],source[second]);
		first++;
		second--;
	}
}

void print(vector<int>& numbers)
{
	for(int i : numbers)
		cout << i << "  ";
}

int main()
{
	vector<int> nums={1,2,3,4,5,6,7,8};
	vector<int> reversed;

	print(nums);
	cout << endl << "Reversed: ";
	first_reverse(nums, reversed);
	print(reversed);
	cout << endl << "Swap reversed: ";
	swap_reverse(nums);
	print(nums);

	return 0;
}
