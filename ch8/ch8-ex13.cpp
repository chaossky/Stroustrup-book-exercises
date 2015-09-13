#include "book.h"

// Write a function that takes a vector<string> argument and returns a vector<int> containing
// the number of characters in each string.  Also find the longest and the shortest string and
// the lexicographically first and last string.  How many separate functions would you use
// for these tasks?  Why?
//
// NOTE:  I would use separate functions for each of these tasks.  It's better if a function
// returns a single number or string, instead of a whole vector full of results that don't
// necessarily mix (for example, a struct with a vector<int> and four strings for short/long/
// first/last...that would be compact, but easy to mess up and not very readable).  It's much
// better to have a separate function for each of the things, that way when you are coding
// with them, you know exactly what you are getting.  That's me.

void lengths(vector<string>& strings, vector<int>& lengths)
{
	lengths.clear();
	for(string s : strings)
		lengths.push_back(s.length());
}

string longest(vector<string>& strings)
{
	string biggest=strings.front();

	for(string s : strings)
		biggest=(s.length()>biggest.length())?s:biggest;
	
	return biggest;
}

string shortest(vector<string>& strings)
{
	string smallest=strings.front();

	for(string s : strings)
		smallest=(s.length()<smallest.length())?s:smallest;

	return smallest;
}

string first(vector<string>& strings)
{
	string first=strings.front();

	for(string s : strings)
		first=(s<first)?s:first;
	
	return first;
}

string last(vector<string>& strings)
{
	string last=strings.front();

	for(string s : strings)
		last=(s>last)?s:last;

	return last;
}


int main()
{
	string inp;

	vector<string> teststrs = {"apple", "Cabana", "joseph smith", "POOP", "Calabash",
								"serious", "yahoO", "23skiddoo", "numerology", "artistic",
								"I rule", "not really", "maybe", "more", "yet more",
								"plots", "PLOTSS", "2cool4u", "Firebreathing!!", "neato",
								"this", "test", "IS", "FINALLy", "done."};

	cout << "Longest string: " << longest(teststrs) << endl
		<< "Shortest string: " << shortest(teststrs) << endl
		<< "Lexicographically first: " << first(teststrs) << endl
		<< "Lexicographically last: " << last(teststrs) << endl
		<< endl << "Type a letter then press ENTER for a list of the strings and their lengths: ";

	cin >> inp;

	vector<int> strlens;
	lengths(teststrs, strlens);

	for(int i=0;i<teststrs.size();i++)
		cout << teststrs[i] << " -- " << strlens[i] << endl;

	return 0;
}
