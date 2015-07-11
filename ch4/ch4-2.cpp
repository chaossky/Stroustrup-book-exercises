#include "book.h"

// The character 'b' is char('a'+1), 'c' is char('a'+2), etc.
// Use a loop to write out a table of characters with their corresponding
// integer values.

int main()
{
	const char START = 'A';

	for(char i=START;i<(START+26);i++) {
		cout << i << '\t' << (int)i << endl;
	}

	return 0;
}
