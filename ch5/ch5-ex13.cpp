#include "book.h"

// Implement a little guessing game called (for some obscure reason)
// "Bulls and Cows."  The program has a vector of four different integers
// in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user's
// task to discover those numbers by repeated guesses.  Say the number
// to be guessed is 1234 and the user guesses 1359; the response should
// be "1 bull and 1 cow" because the user got one digit (1) right and
// in the right position (a bull) and one digit (3) right but in the
// wrong position (a cow).  The guessing continues until the user gets
// four bulls, that is, has the four digits correct and in the correct
// order.

// Exercise 13:  Implement a random-number algorithm to choose the answer,
// and give the player the option to play over and over again.

int main()
{
	int inp;
	string conf;
	vector<int> answer = {7, 4, 7, 7};
	vector<int> guess;
	vector<bool> achk = {false, false, false, false};
	vector<bool> gchk = {false, false, false, false};

	// Input will be a 4 digit number (no spaces).
	// Then we'll parse it into a vector before checking it.
	cout << "Enter a number: ";
	if (!(cin>>inp)) {
		cout << "Nope." << endl;
		return 0;
	}
	srand(inp);
	for(int i=0;i<answer.size();i++) {
		answer[i]=rand()%10;
	}
	cout << "COWS AND BULLS" << endl
		<< "I am thinking of a 4 digit number (e.g., 2345)" << endl
		<< "You will try and guess what that 4 digit number is." << endl
		<< "After you guess, I will tell you how many cows and bulls\n"
		<< "you have." << endl << endl
		<< "Cow -- Right digit, wrong position." << endl
		<< "3278 = 2 cows, 0 bulls." << endl
		<< "Bull -- Right digit, right position." << endl
		<< "2356 = 1 cow, 2 bulls." << endl
		<< "Entering a number less than 1000 will assume the leading\n"
		<< "digits to be zeroes.  Guessing 89 will assume 0089.\n\n"
		<< "Enter any input to begin: ";
	cin >> conf;
	cout << "I have thought of my number." << endl;

	while(true) {
		cout << "Enter your number: ";

		// Yes, I am a bit tired of quitting the whole program when
		// bad input comes in, but handling it properly takes too much
		// other crap that I haven't even gotten to in the book yet, so
		// this is the safest way.

		if(!(cin>>inp)) {
			cout << "Non-integer input.  Program terminated." << endl;
			return 0;
		}
		if(inp>9999) {
			cout << "The number is only 4 digits long." << endl;
			continue;
		}
		if(inp<0) {
			cout << "The number is not negative." << endl;
			continue;
		}

		guess.clear();
		cout << "Your guess is: ";

		// Parse into 4 digits.
		for(int i=0;i<4;i++) {
			int tmp=pow(10,3-i);
			guess.push_back((inp-(inp%tmp))/tmp);
			inp-=tmp*guess[i];
			cout << guess[i];
		}

		cout << endl;
		// Reset the check vectors
		for(int i=0;i<achk.size();i++) {
			achk[i]=false;
			gchk[i]=false;
		}
		// First figure the number of bulls.
		// Check vectors make sure that a number doesn't get 
		// checked twice.
		int bls=0;
		for(int i=0;i<guess.size();i++) {
			if(guess[i]==answer[i]) {
				achk[i]=true;
				gchk[i]=true;
				bls++;
			}
		}
		// Now figure cows.
		int cws=0;
		for(int g=0;g<guess.size();g++) {
			if(!gchk[g]) {
				for(int a=0;a<answer.size();a++) {
					if(!achk[a]) {
						if((a!=g)&&guess[g]==answer[a]) {
							achk[a]=true;
							gchk[g]=true;
							cws++;
							break;
						}
					}
				}
			}
		}

		cout << bls << " bulls, " << cws << " cows." << endl;
		if(bls==4) {
			cout << "4 bulls!  That's the number!  You win!" << endl;
			for(int i=0;i<answer.size();i++) {
				answer[i]=rand()%10;
			}
			string yn="";
			while(!(yn=="y"||yn=="Y"||yn=="n"||yn=="N")) {
				cout << "Play again (Y/N)? ";
				cin >> yn;
			}
			if(yn=="n"||yn=="N") return 0;
			cout << "I have thought of my number." << endl;
		}
	}

	return 0;
}
