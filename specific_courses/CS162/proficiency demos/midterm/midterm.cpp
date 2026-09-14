#include <iostream>
#include <cctype>
#include <cctype>

#include <random>

using namespace std;

int main()
{
	// -LOOPS----------------------------------------------------------------
	cout << "-LOOPS------------------------------------------------------\n";
	// counter: sum every odd number from [3..35] using a for loop
	{
		int sum = 0; // accumulator
		// for (init; cond; post)
		for (int i = 3; i <= 35; i += 2) {
			sum += i;
		}
		cout << "sum [3..35; odd] = " << sum << '\n';
	}

	// while loop:
	cout << '\n';
	{
		int sum = 0;
		int i = 5;
		while (i <= 30) {
			sum += i;
			i += 2;
		}

		cout << "sum [5..30; even] = " << sum << '\n';
	}

	// do-while loop:
	cout << '\n';
	{
		char choice;
		bool valid_input;

		do {
			valid_input = true;

			cout << ">>> enter a char ([q]uit): ";
			
			if (cin.peek() == '\n') {
				cerr << "\t*** zero characters is invalid\n";
				cin.ignore();
				valid_input = false;
				continue;
			}
			
			cin.get(choice);
			
			if (cin.peek() != '\n') {
				cerr << "\t*** too many characters; only enter one at a time\n";
				valid_input = false;
			}
			
			cin.ignore(100, '\n');
		} while (tolower(choice) != 'q' or not valid_input);
	}

	// -ARRAYS---------------------------------------------------------------
	cout << "\n-ARRAYS-----------------------------------------------------\n";

	// char array: make a valid c-string that holds "hi"
	{
		char hi[3] = {'h', 'i', '\0'};
		cout << hi << '\n'; 
	}

	// regular array syntax: make an array of 10 numbers
	cout << '\n';
	{
		int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		cout << "nums: [" << nums[0] << ", " << nums[1]
			 << ", ... , " << nums[9] << "]\n";
	}

	// -LOOPS & ARRAYS (together)--------------------------------------------
	cout << "\n-LOOPS & ARRAYS (together)----------------------------------\n";
	
	// capitalize every word in sentence
	{
		char my_sentence[] = "hello, world!";

		cout << "sentence: " << my_sentence << '\n';

		cout << "uppercasing each word...\n";

		bool start_of_word = true;
		for (int i = 0; my_sentence[i] != '\0'; ++i) { // for each character (@index)
			char c = my_sentence[i];

			if (isspace(c)) { // flag @space so next character is seen as start of word
				start_of_word = true;
			}
			else if (start_of_word and isalpha(c)) { // after space and is a character
				my_sentence[i] = toupper(c);
				start_of_word = false;
			}
		}

		cout << "sentence: " << my_sentence << '\n';
	}

	// add even numbers from an array together
	cout << '\n';
	{
		const int SIZE = 4096;
		int random_numbers[SIZE];

		// -IGNORE BETWEEN THESE LINES (just filling the array)--------
		{
			// NOTE: if you're curious what I'm doing here:
			// https://en.cppreference.com/w/cpp/numeric/random.html
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution dist(0, 99);

			for (int i = 0; i < SIZE; ++i) {
				random_numbers[i] = dist(gen);
			}
		}
		// ------------------------------------------------------------
		
		int sum = 0;

		for (int i = 0; i < SIZE; ++i) {
			int n = random_numbers[i];
			
			if (n % 2 == 0) {
				sum += n;
			}
		}

		cout << "sum of random array = " << sum << '\n';
	}

	return 0;
}
