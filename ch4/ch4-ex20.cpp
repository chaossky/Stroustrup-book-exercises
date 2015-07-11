#include "book.h"

// Write a program where you first enter a set of name-and-value pairs,
// such as Joe 17 and Barbara 22.  For each pair, add the name to a
// vector called names and the number to a vector called scores (in
// corresponding positions, so that if names[7]=="Joe" then scores[7]
// ==17).  Terminate input with NoName 0.  Check that each name is unique
// and terminate with an error message if a name is entered twice.
// Write out all the (name,score) pairs, one per line.

// Exercise 20:  Modify the program from exercise 19 so that when you
// enter a name, the program will output the corresponding score
// or "score not found".

int main()
{
	vector<string> names;
	vector<int> scores;
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
		for(string n : names) {
			if(n==inpname) {
				cout << "You already entered this name." << endl;
				cout << "Terminating program." << endl;
				return 0;
			}
		}
		names.push_back(inpname);
		scores.push_back(inpscore);
		cout << "Stored in memory." << endl;
	}

	cout << "Input ended.  You typed in NoName with a score of 0.\n\n";

	// If vectors are empty, give the empty message.

	if(!names.size()) {
		cout << "There's nothing in memory." << endl;
		return 0;
	}

	inpname="";
	cout << "The name 'NoName', or invalid input will terminate the program." << endl;
	cout << "Enter a name to retrieve the score: ";
	while(true) {
		cin>>inpname;
		bool found=false;
		if(inpname=="NoName") break;
		for(int i=0;i<names.size();i++) {
			if(inpname==names[i]) {
				cout << "The score for " << inpname << " is " << scores[i] << endl;
				found=true;
			}
		}
		if(!found)
			cout << "There was no score for the name " << inpname << endl;
		cout << "Enter a name to retrieve the score: ";
	}
	cout << "Program terminated." << endl;
	return 0;
}

