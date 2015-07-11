#include "book.h"

// Create a program to find all the prime numbers between 1 and 100.
// One way to do this is to write a function that will check if a number
// is prime (i.e., see if the number can be divided by a prime number
// smaller than itself) using a vector of primes in order (so that if the
// vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.)
// Then write a loop that goes from 1 to 100, checks each number to see if
// it is a prime, and stores each prime found in a vector.  Write another
// loop that lists the primes you found.  You might check your result by
// comparing your vector of prime numbers with primes.  Consider 2 the
// first prime.

int main()
{
	vector<int> primes;
	const int MAX=100;

	primes.push_back(2);			// Prime the pump :)
	for(int i=3; i<=MAX; i++) {
		bool isprime=true;
		for(int p : primes) {
			if(i%p==0)
				isprime=false;
		}
		if(isprime)
			primes.push_back(i);
	}

	cout << "Prime numbers from 2 to " << MAX << " are:" << endl;
	for(int p : primes)
		cout << p << " ";

	return 0;
}
