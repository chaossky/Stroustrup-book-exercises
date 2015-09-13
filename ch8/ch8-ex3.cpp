#include "book.h"

// Exercise 3:  Create a vector of Fibonacci numbers and print them using the function from
// exercise 2.  To create the vector, write a function, fibonacci(x,y,v,n), where integers
// x and y are ints, v is an empty vector<int>, and n is the number of elements to put into
// v; v[0] will be x and v[1] will be y.  A Fibonacci number is one that is part of a
// sequence where each element is the sum of the two previous ones.  For example, starting
// with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21,....Your fibonacci() function should make
// such a sequence starting with its x and y arguments.

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
	int x=1;
	int y=2;
	int n=5;
	vector<int> v;

	cout << "First two numbers are: "<< x <<" and "<< y << endl;

	fibonacci(x,y,v,n);
	string fiblabel="Fibonacci sequence, "+to_string(n)+" elements";
	print(fiblabel,v);

	return 0;
}
