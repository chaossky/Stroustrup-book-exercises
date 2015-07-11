#include "book.h"

// Write a program that takes an input value n and then finds the first
// n primes.

// This is pretty much a small modification on ch4-ex11.cpp.

int main()
{
	vector<int> primes;
	int numprimes=1;

	cout << "Find the first n prime numbers." << endl;
	cout << "Value for n: ";
	if((!(cin>>numprimes))||numprimes<1) {
		cout << "Invalid input." << endl;
		return 0;
	}
	primes.push_back(2);			// Prime the pump :)
	for(int i=3; primes.size()<numprimes; i++) {
		bool isprime=true;
		for(int p : primes) {
			if(i%p==0)
				isprime=false;
		}
		if(isprime)
			primes.push_back(i);
	}

	cout << "First " << numprimes << " prime numbers are:" << endl;
	for(int p : primes)
		cout << p << " ";

	return 0;
}
