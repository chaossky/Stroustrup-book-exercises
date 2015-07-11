#include "book.h"

// Implement square() without using the multiplication operator; that is,
// do the x*x by repeated addition (start a variable result at 0 and add
// x to it x times).  Then run some version of "the first program" using
// that square().

int square(int x);

int main()
{
	for(int i=0;i<10;i++) {
		cout << i << '\t' << square(i) << endl;
	}

	return 0;
}

int square(int x)
{
	int t=0;
	for(int i=0;i<x;i++) {
		t+=x;
	}

	return t;
}

