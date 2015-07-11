#include "book.h"

// Write a program that plays the game "Rock, Paper, Scissors."  Use a
// switch statement to solve this exercise.  Also, the machine should
// give random answers (i.e., select the next rock, paper, or scissors
// randomly).  Real randomness is too hard to provide just now, so just
// build a vector with a sequence of values to be used as "the next value".
// If you build the vector into the program, it will always play the same
// game, so maybe you should let the user enter some values.  Try
// variations to make it less easy for the user to guess which move the
// machine will make next.

// Fuck those variations, I'll save it for when we learn random numbers.

int main()
{
	vector<int> compmoves;
	vector<string> movenames;
	int usermove;
	int count=0;
	int wins=0;
	int losses=0;
	int cwins=0;

	// Put the move names in the vector.

	movenames.push_back("ROCK");
	movenames.push_back("PAPER");
	movenames.push_back("SCISSORS");

	// Put 8 moves into compmoves.

	compmoves.push_back(0);
	compmoves.push_back(2);
	compmoves.push_back(1);
	compmoves.push_back(2);
	compmoves.push_back(2);
	compmoves.push_back(0);
	compmoves.push_back(0);
	compmoves.push_back(1);

	// Start the game.

	cout << "ROCK PAPER SCISSORS" << endl;
	cout << "0 -- ROCK | 1 -- PAPER | 2 -- SCISSORS" << endl;
	cout << "-----" << endl;
	cout << "Your move: ";
	while(cin>>usermove) {
		bool win=false;
		if(usermove<0||usermove>2) {
			cout << "Sorry, no DYNAMITE, try again." << endl;
			cout << "Your move: ";
			continue;
		}
		cout << "Your move is " << movenames[usermove] << ".\n";
		cout << "My move is " << movenames[compmoves[count]] << ".\n";

		// Figure out win or loss.
		// Nested switches YOLO LOLOLOL

		switch(usermove) {
			case 0:
				switch(compmoves[count]) {
					case 0:
						cout << "That was a tie." << endl;
						break;
					case 1:
						cout << "You lose, bro." << endl;
						cwins=0;
						losses++;
						cout << "You have lost " << losses
							<< " times." << endl;
						break;
					case 2:
						cout << "Ya beat me." << endl;
						cwins++;
						wins++;
						cout << "You have won " << wins
							<< " times." << endl;
						break;
					default:
						cout << "Oops." << endl;
						break;
				}
				break;
			case 1:
				switch(compmoves[count]) {
					case 0:
						cout << "I be defeated." << endl;
						cwins++;
						wins++;
						cout << "You have won " << wins
							<< " times." << endl;
						break;
					case 1:
						cout << "That was a tie." << endl;
						break;
					case 2:
						cout << "I beat ya." << endl;
						cwins=0;
						losses++;
						cout << "You have lost " << losses
							<< " times." << endl;
						break;
					default:
						cout << "Uh-oh." << endl;
						break;
				}
				break;
			case 2:
				switch(compmoves[count]) {
					case 0:
						cout << "HULK SMASH." << endl;
						cwins=0;
						losses++;
						cout << "You have lost " << losses
							<< " times." << endl;
						break;
					case 1:
						cout << "You cut me up." << endl;
						wins++;
						cwins++;
						cout << "You have won " << wins
							<< " times." << endl;
						break;
					case 2:
						cout << "That was a tie." << endl;
						break;
					default:
						cout << "That's not right..." << endl;
						break;
				}
				break;
			default:
				cout << "How strange..." << endl;
				break;
		}
		if(cwins>5)
			cout << "I think you're on to me..." << endl;

		cout << endl;

		count++;
		count=(count>=compmoves.size())?0:count;
		cout << "Your move: ";
	}

	cout << "TERMINATED.";
	return 0;
}
