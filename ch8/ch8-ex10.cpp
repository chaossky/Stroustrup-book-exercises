#include "book.h"

// Exercise 10:  Write a function maxv() that returns the largest element of a vector argument.
//
// NOTE:  I am not sure how to completely generalize this for vectors of all types, aside
// from writing it six times or whatever.  So I am just going to do it for ints.

int maxv(vector<int>& nums)
{
	if(!nums.size()) return 0;

	int mostest=nums.front();

	for(int i : nums)
		if(i>mostest) mostest=i;

	return mostest;
}

int main()
{
	vector<int> nums = {3,4,44,444,2,23,98};

	cout << "Biggest number in nums is: "<<maxv(nums)<<endl;

	return 0;
}
