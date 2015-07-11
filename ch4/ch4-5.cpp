#include "book.h"

// Write a program that "bleeps" out words that you don't like; that is,
// you read in words using cin and print them again on cout.  If a word
// is among a few you have defined, you write out BLEEP instead of
// that word.  Start with one "disliked word" such as
//
// string disliked="Broccoli";
//
// When that works, add a few more.

int main()
{
	vector<string> disliked = {"damn","hell","piss","dick","bologna"};
	vector<string> words;

	cout << "Type some words and I'll bleep out the bad ones.\n\n";
	cout << "Bad words are:" << endl;
	for(string s : disliked)
		cout << s << " ";
	cout << endl;

	// Stuff words into vector words

	string temp;
	cout << "Type words, then do Ctrl-D to end input.\n" << ">";
	while(cin >> temp)
		words.push_back(temp);
	
	cout << endl << "There are " << words.size() << " words in the buffer.\n";
	cout << "The contents of vector words are: " << endl << endl;
	for(string s : words) {
		for(string w : disliked)
			if(s==w) {s="BLEEP"; break;}
		cout << s << " ";
	}
	cout << endl;
	cout << "Program complete so far." << endl;

}
