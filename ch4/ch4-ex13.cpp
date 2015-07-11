#include "book.h"

// Create a program to find all the prime numbers between 1 and 100.
// There is a classic method for doing this, called the "Sieve of
// Eratosthenes."  If you don't know that method, get on the web and look
// it up.  Write your program using this method.

int main()
{
	unsigned int MAX;
	vector<bool> sieve;
	int sifter=2;

	cout << "Enter a max value for prime numbers: ";
	if((!(cin>>MAX))||MAX<2) {
		cout << "Invalid number." << endl;
		return 0;
	}
	// I guess I'll use a boolean vector as the "sieve".  Each number
	// that is sifted will be marked false.  After the sieve is complete,
	// only the true elements will be primes.

	for(int i=0;i<MAX;i++)
		sieve.push_back(true);

	// The sieve starts with 2, and marks out all multiples of 2.  Then
	// multiples of 3.  Then multiples of 5.  Basically, after crossing off
	// a number, the next number that hasn't been sifted becomes the
	// multiple to sift by.  Really, the other implementation was much
	// better...

	// 1 is neither prime nor composite.

	sieve[0]=false;

	for(;;) {
		// cout << "Sifter " << sifter << ": ";
		for(int i=sifter*2;i<=sieve.size();i+=sifter) {
			sieve[i-1]=false;
		//	cout << i << " ";
		}
		int temp=sifter;
		for(int i=sifter+1;i<=sieve.size();i++)
			if(sieve[i-1]) {
				sifter=i; 
				break;
			}
		if(temp==sifter) break;

		cout << endl;
	}

	cout << "Sieve complete." << endl << endl;

	// Haven't learned how to access the iterator in a foreach loop
	// yet, so I'm doing it the old-fashioned way...

	cout << "Unsifted numbers are: ";
	for(int i=0;i<sieve.size();i++)
		if(sieve[i]) cout << i+1 << " ";
	cout << endl;

	return 0;
}
