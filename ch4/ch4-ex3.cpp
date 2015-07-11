#include "book.h"
#include <float.h>

// Read a sequence of double values into a vector.  Think of each value
// as the distance between two cities along a given route.  Compute
// and print the total distance (the sum of all distances).  Find and
// print the smallest and greatest distance between two neighboring
// cities.  Find and print the mean distance between two neighboring
// cities.

int main()
{
	vector<double> dist;
	double smallest=DBL_MAX;
	double largest=DBL_MIN;
	double total=0;
	double inp;

	cout << "Enter distances, separated by spaces or <ENTER>"<< endl;
	cout << "Enter non-numeral input to stop and get results." << endl;
	cout << ">";

	while(cin>>inp) {
		dist.push_back(inp);
		smallest=(inp<smallest)?inp:smallest;
		largest=(inp>largest)?inp:largest;
		total+=inp;
	}
	if(dist.size()==0) {smallest=0; largest=0;}
	cout << "-----\n"
		<< "Smallest distance: " << smallest << endl
		<< "Largest distance: " << largest << endl
		<< "Number of distances: " << dist.size() << endl
		<< "Total distance: " << total << endl
		<< "Average distance: " << total/dist.size() << endl
		<< "-----\n"
		<< "End of output." << endl;

	return 0;
}

