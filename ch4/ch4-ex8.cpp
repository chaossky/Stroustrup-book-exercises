#include "book.h"

// There is an old story that the emperor wanted to thank the inventor
// of the game of chess and asked the inventor to name his reward.  The
// inventor asked for one grain of rice for the first square, 2 for the
// second, 4 for the third, and so on, doubling for each of the 64
// squares.  That may sound modest, but there wasn't that much rice
// in the empire!  Write a program to calculate how many squares are
// required to give the inventor at least 1000 grains of rice, at least
// 1,000,000 grains, and at least 1,000,000,000 grains.  You'll need a
// loop, of course, and probably an int to keep track of which square
// you are at, an int to keep the number of grains on the current
// square, and an int to keep track of the grains on all previous squares.
// We suggest that you write out the value of all your variables for
// each iteration of the loop so that you can see what's going on.

int squares(long int rice);			// Count squares for rice.

int main()
{
	
	cout << "The chessboard starts with one grain of rice on the first\n"
		<< "square, two grains on the second, four on the third, doubling\n"
		<< "the amount of rice on each square." << endl << endl;

	cout << "A thousand grains of rice are on " << squares(1000)
		<< " squares." << endl;
	cout << "A million grains of rice are on " << squares(1000000)
		<< " squares." << endl;
	cout << "A billion grains of rice are on " << squares(1000000000)
		<< " squares." << endl;
	cout << "I can barely imagine how much rice would be on the whole\n"
		<< "chessboard..." << endl;

	return 0;
}

int squares(long rice)
{
	int sqcount=1;
	long ricecount=1;
	
	// There is a math trick for this chessboard problem.  The contents
	// of a square minus one equals the total contents of all of the
	// previous squares.  That will make this a bit simpler.

	while(ricecount<rice) {
		ricecount*=2;
		sqcount++;
	}

	return sqcount-1;
}
