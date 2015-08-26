#include "book.h"

// Write a program that checks if a sentence is correct according to 6.4.1.  Assume
// that every sentence is terminated by a full stop (.) surrouonded by whitespace.  For
// example, "birds fly but the fish swim . " is a sentence, but "birds fly but the fish
// swim" (terminating dot missing) and "birds fly but the fish swim." (no space before dot)
// are not.  For each sentence entered, the program should simply respond "OK" or "not OK."
// Hint: Don't bother with tokens; just read into a string using >>.


vector<string> noun;
vector<string> verb;
vector<string> conjunction;

// Little functions that return true if a word is valid

bool is_noun(string word)
{
	for(string s : noun)
		if(word==s) return true;
	return false;
}

bool is_verb(string word)
{
	for(string s : verb)
		if(word==s) return true;
	return false;
}

bool is_conjunction(string word)
{
	for(string s : conjunction)
		if(word==s) return true;
	return false;
}

// Test if a word and the word after it are noun/verb.
// is_sentence will up the iterator by 2 if so.

bool nounverb(vector<string> sentence, int wordcount)
{
	if(is_noun(sentence[wordcount]))
		if(is_verb(sentence[wordcount+1]))
			return true;
	return false;
}

// Parse a sentence, return true if it is a valid sentence according to the grammar.
// wordcount denotes which element of the vector to read from.

bool is_sentence(vector<string> sentence, int wordcount)
{
	int c=wordcount;
	if(nounverb(sentence,c)) {
		c+=2;
		if(is_conjunction(sentence[c])) {
			return is_sentence(sentence,c+1);
		}
		if(sentence[c]==".")
			return true;
	}
	return false;
}
	
int main()
{
	const string END = ".";

	vector<string> words;
	string inp;

	// push_back nouns

	noun.push_back("birds");
	noun.push_back("fish");
	noun.push_back("C++");

	// push_back verbs

	verb.push_back("fly");
	verb.push_back("swim");
	verb.push_back("rules");

	// push back conjunctions

	conjunction.push_back("but");
	conjunction.push_back("or");
	conjunction.push_back("and");

	cout << "Enter a sentence, and I'll tell you if it is any good." << endl;
	cout << "> ";

	while(cin>>inp, inp!=END) {
		words.push_back(inp);
	}
	words.push_back(END);

	cout << ((is_sentence(words,0))?
		"OK.\n"
		:"Not OK.\n");
	return 0;
}
