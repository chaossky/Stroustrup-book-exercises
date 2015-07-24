#include "book.h"

// Find a pair of values so that the pre-condition of this version of
// area holds, but the post-condition doesn't.

// Seems impossible...

int area(int length, int width)
// calculate the area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
	if(length<=0 || width<=0)
		cout << "length or width are non-positive" << endl;
	int a=length*width;
	if(a<=0)
		cout << "area is non-positive" << endl;
	return a;
}

int main()
{
	int l,w,a;

	cout << "Enter two integers: ";
	while(cin>>l>>w) {
		a=area(l,w);
		cout << "Length: " << l << ", Width: " << w
			<< ", Area: " << a << endl << endl;
		cout << "Enter two integers: ";
	}
	cout << "Program terminated.";

	return 0;
}
