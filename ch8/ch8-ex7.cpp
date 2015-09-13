#include "book.h"

// Exercise 7:  Read five names into a vector<string> name, then prompt the user for the ages
// of the people named and store the ages in a vector<double> age.  Then print out the five
// (name[i],age[i]) pairs.  Sort the names (sort(name.begin(),name.end())) and print out
// the (name[i],age[i]) pairs.  The tricky part here is to get the age vector in the
// correct order to match the sorted name vector.  Hint:  Before sorting name, take a copy
// and use that to make a copy of age in the right order after sorting name.  Then, do
// that exercise again but allowing an arbitrary number of names.

// NOTE:  There is a much easier way to do this with structs.  If Mr. Stroustrup wants to
// test my logic...nice try, buddy.

typedef struct person
{
	string name;
	int age;
	person(string str, double dbl): name(str), age(dbl) {}
} person;

// These two functions allow sort() to sort by name or age.

bool person_name_compare(person one, person two) { return one.name<two.name; }
bool person_age_compare(person one, person two) { return one.age<two.age; }

int main()
{
	// SAMPLE_SIZE allows an arbitrary sample size.

	const int SAMPLE_SIZE = 5;

	vector<person> people;
	vector<string> names;
	vector<double> ages;

	string name_input;
	double age_input;

	// Get names.

	cout << "Enter "<<SAMPLE_SIZE<<" single word names." << endl << endl;

	for(int i=1;i<SAMPLE_SIZE+1;i++) {
		cout << "Person "<<i<<": ";
		cin >> name_input;
		names.push_back(name_input);
	}

	cout << SAMPLE_SIZE << " names input: ";
	for(string s : names)
		cout << s << "  ";
	
	cout << endl;
	cin.clear();
	cin.ignore(1000000,'\n');

	// Get ages.

	for(string s : names) {
		cout << "Enter "<<s<<"'s age: ";
		cin >> age_input;
		ages.push_back(age_input);
	}

	cout << SAMPLE_SIZE << " ages input: ";
	for(double d : ages) {
		cout << d << "  ";
	}

	// Put names and ages into people.

	for(int i=0;i<names.size();i++)
		people.push_back(person(names[i],ages[i]));

	// Sort people by name.

	sort(people.begin(), people.end(), person_name_compare);

	// Put people back into names and ages, sorted.

	names.clear();
	ages.clear();

	for(person p : people) {
		names.push_back(p.name);
		ages.push_back(p.age);
	}

	// This should be sorted.

	cout << endl << "------------" << endl
	<< "Names and ages, sorted by name:" << endl;

	for(int i=0;i<names.size();i++)
		cout << names[i] << ", age " << ages[i] << endl;

	// Done.

	cout << endl << "Thanks for playing!" << endl;

	return 0;
}
