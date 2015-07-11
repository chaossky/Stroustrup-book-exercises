#include "book.h"

// If we define the median of a sequence as "a number so that exactly as
// many elements come before it in the sequence as come after it," fix
// the program in 4.6.3 (this program) so that it always prints out a
// median.  Hint:  A median need not be an element of the sequence.

// compute mean and median temperatures

int main()
{
	vector<double> temps;

	for(double temp; cin>>temp; )
		temps.push_back(temp);
	
	// compute the mean (average) temperature
	double sum=0;
	for(int x : temps) sum += x;
	cout << "Average temperature: " << sum/temps.size() << endl;

	// compute median temperature
	sort(temps.begin(), temps.end());
	double median = ((double)temps.size()/2==temps.size()/2)?
		(temps[temps.size()/2]+temps[temps.size()/2-1])/2:
		temps[temps.size()/2];
	cout << "Median temperature: " << median << endl;

	return 0;
}
