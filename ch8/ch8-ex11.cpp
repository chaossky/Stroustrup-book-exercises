#include "book.h"

// Write a function that finds the smallest and the largest element of a vector argument and
// also computes the mean and the median.  Do not use global variables (OK DAD).  Either
// return a struct containing the results or pass them back through reference arguments.
// Which of the two ways of returning several result values do you prefer and why?
//
// I think I'd rather do this through a vector<double>, because it's a bit friendlier.
// vector<double> already exists as a type, whereas a custom struct would require more
// knowledge for the coder.  The point is to make it easier, not harder...vectors it is.

// Results will be output into result vector as:  smallest, largest, mean, median.

void vector_stats(vector<double>& input, vector<double>& result)
{
	vector<double> sorted;
	double min, max, mean, median;
	int elements=input.size();

	if(!elements) {
		cerr << "vector_stats:  input vector must not be empty" << endl;
		return;
	}

	min=input.front();
	max=input.front();
	mean=0;

	// Min, max, and mean captured on the fly.
	// On-the-fly mean is slower (more divisions), but it can handle a practically
	// infinite sized array of very large numbers...so it's better.

	for(int i=0; i<elements; i++) {
		min=(input[i]<min)?input[i]:min;
		max=(input[i]>max)?input[i]:max;
		mean+=(input[i]-mean)/(i+1);
		result.push_back(input[i]);
	}

	sort(result.begin(), result.end());

	median=(elements%2)?
		result[elements/2]
		:(result[elements/2]+result[elements/2-1])/2;

	// Push back results and that's it.

	result.clear();
	result.push_back(min);
	result.push_back(max);
	result.push_back(mean);
	result.push_back(median);
}

int main()
{
	vector<double> testnums = {4.5, 2, 34.8, 33, 45, 86.75, 21, 12, 23};
	vector<double> results;

	cout << "testnums: ";
	for(double d : testnums)
		cout << d << "  ";
	cout << endl;

	vector_stats(testnums, results);

	cout << "Results for testnums:" << endl;
	cout << "Min: " << results[0] << endl;
	cout << "Max: " << results[1] << endl;
	cout << "Mean: " << results[2] << endl;
	cout << "Median: " << results[3] << endl;

	return 0;
} 

