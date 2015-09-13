#include "book.h"

// Exercise 9:  Write a function that given two vector<double>s, price and weight, computes
// a value (an "index") that is the sum of all price[i]*weight[i].  Make sure to have
// weight.size()==price.size().

double total_price(vector<double>& price, vector<double>& weight)
{
	double tmp;

	if(price.size()!=weight.size()) {
		cerr << "total_price: price vector and weight vector must be the same size" << endl;
		return -1;
	}

	for(int i=0;i<price.size();i++)
		tmp+=(price[i]*weight[i]);

	return tmp;
}

int main()
{
	vector<double> price = {1.00, 4.00, .45, 2.6, 1.50};
	vector<double> weight = {1, 2, 3, 4, 5};

	cout << "Total bill comes to: " << total_price(price, weight) << endl;

	return 0;
}
