#include "book.h"

// A permutation is an ordered subset of a set.  For example, say you wanted to pick a
// combination to a vault.  There are 60 possible numbers, and you need three different
// numbers for the combination.  There are P(60,3) permutations for the combination, where
// P is defined by the formula P(a,b)=a!/(a-b)! where ! is the factorial suffix.
//
// Combinations are similar to permutations, except that the order of the objects doesn't
// matter.  For example, if you were making a "banana split" sundae and wished to use
// three different flavors of ice cream out of five that you had, you wouldn't care if
// you used a scoop of vanilla at the beginning or the end;  you would still have used
// vanilla.  The formula for combinations is C(a,b)=P(a,b)/b!
//
// Design a program that asks users for two numbers, asks them whether they want to
// calculate permutations or combinations, and prints out the result.  This will have
// several parts.  Do an analysis of the above requirements.  Write exactly what the
// program will have to do.  Then, go into the design phase.  Write pseudo code for the
// program, and break it into sub-components.  This program should have error checking.
// Make sure that all erroneous inputs will generate good error messages.

// ----------------------------------------------------------------------

// ANALYSIS:  
// The program should clearly state what it does.
// The program must correctly handle input.
// The program should throw clear errors if the input is bad.
// The program must correctly calculate permutations and combinations. 

// ----------------------------------------------------------------------

// Factorial function that accepts two bounds.

long factorial(int high, int low=1)
{
	long tmp=1;
	for(int i=high;i>=low;tmp*=i--)

		// Simple error check for if the factorial goes beyond long range,
		// it returns 0 if the long suddenly goes negative.
		// No factorial will return 0 normally, so if you get 0 it's too big.
		// Also, due to the nature of the permutation/combination equations,
		// they will all return 0 if the factorial is too big.  This should
		// adequately and elegantly cover any problems with mathematical bounds.

		if(tmp<0) return 0;
	return tmp;
}

// P(a,b) function for calculating permutations.
// P(a,b) = a!/(a-b)!

long permutation(int possible, int choices)
{
	return factorial(possible,possible-choices+1);
}

// C(a,b) function for calculating combinations.
// C(a,b) = permutation(a,b)/b!

long combination(int possible, int choices)
{
	return permutation(possible, choices)/factorial(choices);
}

int main()
{
	long result;
	int possibilities, choices;
	int inp;

	// State what it does.

	cout << "\nPermutation/combination calculator.\n\n";
	cout << "Choose permutations or combinations, then enter the number of picks\n"
		<< "and the number of possibilities.\n" << endl;

	// Accept input.
	// Throw an error if the input is wrong.

	cout << "1) Permutations\n" << "2) Combinations\n" << endl;
	cout << "Enter your choice: ";
	while((cin>>inp),inp<1||inp>2) {
		cout << "Please choose 1 or 2: ";
		cin.clear();
		cin.ignore(1000000,'\n');
	}

	cout << "Number of possibilities: ";
	while((cin>>possibilities),possibilities<1) {
		cout << "Please enter an integer greater than zero: ";
		cin.clear();
		cin.ignore(1000000,'\n');
	}

	cout << "Number of choices from "<<possibilities<<" possibilities: ";
	while((cin>>choices),choices<1||choices>possibilities) {
		cout << ((choices<1)?
			"Please enter an integer greater than zero: "
			:"The number of choices must not be greater than the possibilities: ");
		cin.clear();
		cin.ignore(1000000,'\n');
	}

	cout << "\nThe operation is: " << ((inp==1)?"permutations.\n":"combinations.\n");
	cout << "Possibilities to choose from: " << possibilities<< endl;
	cout << "Choices to make: " << choices << endl;

	// Calculate permutations/combinations.

	result=((inp==1)?permutation(possibilities,choices)
		:combination(possibilities,choices));
	cout << "Number of " << ((inp==1)?"permutations: ":"combinations: ");
	if(result)
		cout << result;
	else
		cout << "The result was too large for the program to handle.";
	cout << endl;
			
	// That's it.
	
	return 0;
}
