#include "book.h"

// Exercise 4:  An int can hold integers only up to a maximum number.  Find an approximation
// of that maximum number by using fibonacci().

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.clear();
	v.push_back(x);
	v.push_back(y);

	// The most intuitive way to do this, I think, is to have n be the total numbers you want
	// in v.  If you specify less than 3 (there is nothing to add or you accidentally asked
	// for less than two fibs), then it will return a vector with only the first two numbers
	// in it.  Otherwise, the vector will have a total of n fibs in it.

	if(n<3) return;
	n-=2;

	for(int i=1;i<=n;i++)
		v.push_back(v[i-1]+v[i]);
}

void print(string label, vector<int>& nums)
{
	cout << label << ": " << endl;
	for(int i : nums)
		cout << i << endl;
}

int main()
{
	// One way to do this is to keep making fibonacci sequences over and over, until
	// the int overflows.  Seriously, I could do this just by adding 1...really?  OK,
	// whatever, first I will approximate the MAX_INT as the highest term of a "regular"
	// Fibonacci sequence (starts with 1 and 1).

	vector<int> fibs;
	int i=3;

	fibonacci(1,1,fibs,i);

	while(fibs.back()>0) { fibonacci(1,1,fibs,i); i++; }

	fibs.pop_back();

	cout << "Starting with 1 and 1, after "<<i<<" terms, the int finally overflowed.\n"
		<< "The largest Fibonacci number attained was "<<fibs.back()<<"." << endl
		<< "Therefore, the maximum int is somewhat bigger than that..." << endl;

	return 0;
}
