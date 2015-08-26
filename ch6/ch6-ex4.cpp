#include "book.h"

// Write a program where you first enter a set of name-and-value pairs,
// such as Joe 17 and Barbara 22.  For each pair, add the name to a
// vector called names and the number to a vector called scores (in
// corresponding positions, so that if names[7]=="Joe" then scores[7]
// ==17).  Terminate input with NoName 0.  Check that each name is unique
// and terminate with an error message if a name is entered twice.
// Write out all the (name,score) pairs, one per line.

// Chapter 6, Exercise 4:  Define a class Name_value that holds a string and a value.
// Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.

class Name_value
{
	public:
		string name;
		int value;
		Name_value(int val)
			:name("[NONE]"),value(val) {}
		Name_value(string str)
			:name(str),value(0) {}
		Name_value(string str, int val)
			:name(str),value(val) {}
};

int main()
{
	vector<Name_value> nameval;
	string inpname="";
	int inpscore;

	while(true) {
		cout << "Enter a name and a score: ";
		if(!(cin>>inpname>>inpscore)) {
			cout << "The score must be an integer." << endl;
			cout << "Terminating program." << endl;
			return 0;
		}
		if(inpname=="NoName"&&inpscore==0) break;
		cout << "Name: " << inpname << endl;
		cout << "Score: " << inpscore << endl;
		// Check if the name is unique.
		for(int i=0;i<nameval.size();i++) {
			if(nameval[i].name==inpname) {
				cout << "You already entered this name." << endl;
				cout << "Terminating program." << endl;
				return 0;
			}
		}
		nameval.push_back(Name_value(inpname,inpscore));
		cout << "Stored in memory." << endl;
	}

	cout << "Input ended.  You typed in NoName with a score of 0.\n\n";

	// If vectors are empty, give the empty message.

	if(!nameval.size()) {
		cout << "There's nothing in memory." << endl;
		return 0;
	}

	for(int i=0;i<nameval.size();i++)
		cout << "Name: " << nameval[i].name << "\tScore: " << nameval[i].value << endl;

	return 0;
}

