#include "book.h"

// Write a program that writes out the first of so many values of the
// Fibonacci series, that is, the series that starts with 1 1 2 3 5
// 8 13 21 34.  The next number of the series is the sum of the two
// previous ones.  Find the largest Fibonacci number that fits in an
// int.  (Note:  I am going to use the upper bound of an unsigned int
// as the limit.)

int main()
{
	unsigned int bigfib;
	vector<int> fibs;
	unsigned int inp;

	fibs.push_back(1);
	fibs.push_back(1);

	cout << "Fibonacci numbers!  Wheeee!" << endl;
	cout << "(Find the first N Fibonacci numbers) Enter N: ";
	if(!(cin>>inp)) {
		cout << "That input is no good, buddy.  Program done." << endl;
		return 0;
	}
	cout << "You entered " << inp << " for N." << endl;
	// Make Fibonacci numbers if N>2
	for(int i=2;i<inp;i++)
		fibs.push_back(fibs[i-2]+fibs[i-1]);

	cout << "Here's all the fibs you asked for:" << endl;
	for(int i=0;i<inp;i++)
		cout << fibs[i] << " ";
	cout << endl;

	long f1,f2,fib;
	// Calculate fibs with the long, and then test to see if it fits in
	// bigfib.  In a world with no longs, you could probably bet on an
	// overflow to be smaller than the value that came before it, but I'm
	// going to play it safe.

	f1=1;
	f2=1;
	do {
		fib=f1+f2;
		f1=f2;
		f2=fib;
		bigfib=fib;
	} while(bigfib==fib);

	cout << "The last fib that fit into an unsigned int was: "
		<< f1 << "." << endl;
	cout << endl;

	return 0;
}
