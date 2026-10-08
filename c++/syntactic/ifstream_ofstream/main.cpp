#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// --definitions-------------------------------------
const char FILENAME[] = "data.txt";

struct Person
{
	string name;
	unsigned id;
	float rating;
};

// --prototypes--------------------------------------
void read_from_file(const char * FILENAME, vector<Person>& people);
void read_to_file(const char * FILENAME, const vector<Person>& people);



int main()
{
	vector<Person> people;
	cout << "reading from \"" << FILENAME << "\"...\n";
	read_from_file(FILENAME, people);

	int choice;
	do {
		cout << "\n1. display people\n2. add person\n3. quit\n4. quit (without saving)\n>>> ";
		cin >> choice;
		cin.ignore(100, '\n');

		if (cin.fail()) {
			cout << "please enter a valid numeric choice...\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		switch (choice) {
			case 1:
				cout << '\n';
				if (people.empty()) {
					cout << "<NOBODY TO DISPLAY>\n";
				}

				for (const Person& person: people) {
					cout << person.name << '<' << person.id << "> = " << person.rating << '\n';
				}
				break;
			case 2:
				cout << '\n';
				{
					people.emplace_back();
					Person& person = people.back();
					cout << ">>> name: ";
					getline(cin, person.name);
					cout << ">>> id: ";
					cin >> person.id;
					cin.ignore(100, '\n');
					cout << ">>> rating [0.0, 5.0]: ";
					cin >> person.rating;
					cin.ignore(100, '\n');
				}
				break;
			case 3:
				cout << '\n';
				cout << "saving to \"" << FILENAME << "\"...\n";
				read_to_file(FILENAME, people);
				break;
			case 4:
				break;
			default:
				cout << choice  << " is not a menu option.\n";
		}
	} while (not (choice == 3 or choice == 4));

	return 0;
}

// --function implementations------------------------
void read_from_file(const char * FILENAME, vector<Person>& people)
{
	ifstream infile(FILENAME); //ifstream VAR_NAME("filename")

	if (not infile) { return; } // no file to read from
	
	while (true) {
		infile.peek();
		if (infile.eof()) { break; } // is the next line empty?

		{ // local scope lets us use a reference for nice nicknaming :) *
			// EQ: Person& person = array[last];
			people.emplace_back();
			Person& person = people.back(); // --right here*

			getline(infile, person.name, ',');
			infile >> person.id;
			infile.ignore(100, ',');
			infile >> person.rating;
			infile.ignore(100, '\n');
		}
	}
}

/*
void read_from_file(FILENAME, data_structure_holding_people) {
	1. open the file
	2. if the file could not be opened, it doesn't exist, so just leave
	3. while we have more lines to read:
		a. make a new entry in the data structure we're using
		b. read in all of the fields/data members
}
*/

void read_to_file(const char * FILENAME, const vector<Person>& people)
{
	ofstream outfile(FILENAME);

	for (const Person& person: people) {
		outfile << person.name << ',' << person.id << ',' << person.rating << '\n';
	}
}
