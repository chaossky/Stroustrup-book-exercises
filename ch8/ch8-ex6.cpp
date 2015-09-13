#include "book.h"

// Exercise 6:  Write versions of the functions from exercise 5, but with a vector<string>.

void first_reverse(vector<string>& source, vector<string>& target)
{
	target.clear();

	for(int i=source.size()-1;i>=0;i--)
		target.push_back(source[i]);
}

void swap_reverse(vector<string>& source)
{
	int first=0;
	int second=source.size()-1;

	while(first<=second) {
		swap(source[first],source[second]);
		first++;
		second--;
	}
}

void print(vector<string>& strings)
{
	for(string i : strings)
		cout << i << "  ";
}

int main()
{
	vector<string> strs={"one","two","three","four","five","six","seven"};
	vector<string> reversed;

	print(strs);
	cout << endl << "Reversed: ";
	first_reverse(strs, reversed);
	print(reversed);
	cout << endl << "Swap reversed: ";
	swap_reverse(strs);
	print(strs);

	return 0;
}
