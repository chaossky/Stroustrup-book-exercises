#include "book.h"

// Improve print_until_s() from 8.5.2.  Test it.  What makes a good set of test cases?  Give
// reasons.  Then, write a print_until_ss() that prints until it sees a second occurrence of
// its quit argument.
//
// NOTE:  Aside from it being incorrect as shown in the book, it works fine for what it does.
// I think these test cases are decent enough, it's good at birds at least.  Maybe you
// want it to print the stop case with a notification...?  Sure, why not.

void print_until_s(vector<string>& v, string quit)
{
	for(string s : v) {
		if(s==quit) {cout<<s<<" [STOPPED]"<<endl; return;}
		cout << s << endl;
	}
}

void print_until_ss(vector<string>& v, string quit)
{
	bool seenItOnce=false;
	for(string s : v) {
		if(s==quit && seenItOnce) {cout<<s<<" [STOPPED]"<<endl; return;}
		else if(s==quit) {seenItOnce=true; cout<<s<<" [ONE MORE]"<<endl;}
		else cout << s << endl;
	}
}

int main()
{
	vector<string> teststrs={"duck", "Duck", "still a duck", "GOOSE", "flamingo",
							"finch", "bluebird", "stellar jay", "GOOSE", "parrot",
							"hawk", "eagle", "cormorant", "crow"};

	cout << "print_until_s test, eagle: " << endl;
	print_until_s(teststrs, "eagle");
	cout << endl;
	cout << "print_until_ss test, GOOSE: " << endl;
	print_until_ss(teststrs, "GOOSE");

	return 0;
}
