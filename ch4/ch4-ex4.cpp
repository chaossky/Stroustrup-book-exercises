#include "book.h"

// Write a program to play a numbers guessing game.  The user thinks of
// a number between 1 and 100 and your program asks questions to figure
// out what the number is (e.g., "Is the number you are thinking of less
// than 50?").  Your program should be able to identify the number after
// asking no more than seven questions.  Hint: Use the < and <= operators
// and the if-else construct.

int maxguesses(int min, int max);	// Function to determine max guesses
									// for a range of numbers.
									// This way, the game can be easily
									// extended to more than from 1-100.

bool yn(string prompt);				// Returns true if you type in Y
									// or y, false if you type in N
									// or n.  Outputs the string
									// prompt as a prompt.

int main()
{
	// You can change the constants if you want to.
	const int MIN = 1;
	const int MAX = 100;
	
	// Introduction

	cout << "Number guessing game!\n\n"
		<< "You think of a number between " << MIN << " and " << MAX << ".\n";
	if(MAX<MIN) {
		cout << "Wait a second...that can't be right." << endl
			<< "You compiled with your constants backwards." << endl
			<< "Try switching them, and recompiling." << endl;
			return 0;
	}
	if(MAX==MIN) {
		cout << "Wait a second...I think I've got it..." << endl
			<< "Your number is: " << MAX << "!" << endl
			<< "Wheee!  I'm a genius!  Or maybe..." << endl
			<< "...you made the MIN and MAX exactly the same!" << endl
			<< "Try recompiling with different values for MIN and MAX.\n"
			<< "You know, so it's actually a game." << endl;
			return 0;
	}

	int maxg=maxguesses(MIN,MAX);

	cout << "I will have " << maxg << " questions that I can ask you "
		<< "to try and figure it out." << endl
		<< "I never lose at this game, so don't feel bad." << endl
		<< "Answer my questions with Y for yes, or N for no." << endl;
		while(!yn("Type Y to begin: ")) {}

	// Here we go.

	int uppb=MAX;
	int lowb=MIN;
	int guessnum=0;
	int guess=0;

	cout << endl;
	while(guessnum<maxg&&(uppb!=lowb)) {
		guessnum++;
		guess=(uppb+lowb)/2;
		cout << "Question #" << guessnum << ": Is your number greater than "
			<< guess;
		if(yn("? ")) {
			lowb=guess+1;;
		} else {
			uppb=guess;
		}
	}

	cout << "OK, I've got it." << endl;
	cout << "Your number is: " << uppb << ".  Am I right";
	if(yn("? ")) {
		cout << "Yeah, baby!  Until next time!" << endl;
	} else {
		cout << "You lie!  Liar!  Or...maybe I did screw up :( :( :(" << endl;
	}
		
	return 0;
}

int maxguesses(int min, int max)
{
	int rng=max-min+1; 
	int count=0;

	// Count max number of guesses by the worst case scenario.
	while(rng>1) {
		if(rng%2==0) {
			rng/=2;
		} else {
			rng/=2;
			rng++;
		}
		count++;
	}
	
	return count;
}

bool yn(string prompt)
{
	string inp="";
	while(!(inp=="y"||inp=="Y"||inp=="n"||inp=="N")) {
		cout << prompt;
		cin >> inp;
	}
	if(inp=="y"||inp=="Y")
		return true;
	else
		return false;
}
