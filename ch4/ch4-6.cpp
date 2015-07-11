#include "book.h"

// Simple dictionary.

int main()
{
	vector<string> words;
	for(string temp; cin>>temp; )
		words.push_back(temp);
	cout << "Number of words: " << words.size() << endl;

	sort(words.begin(), words.end());

	// Only print distinct words

	for(int i=0; i<words.size(); i++)
		if(i==0 || words[i-1]!=words[i])	// only if the word before
			cout << words[i] << endl;		// is not the same

	return 0;
}
