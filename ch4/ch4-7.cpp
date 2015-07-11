#include "book.h"

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
	cout << "Median temperature: " << temps[temps.size()/2] << endl;

	return 0;
}
