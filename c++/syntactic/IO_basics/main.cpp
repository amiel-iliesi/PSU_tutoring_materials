#include <print>
#include <iostream>
#include <string>

/* Useful documentation links:
 * <iostream>
	 * cin: https://en.cppreference.com/cpp/io/basic_istream
		* cin.good: https://en.cppreference.com/cpp/io/basic_ios/good
 * <string>
	 * getline: https://en.cppreference.com/cpp/string/basic_string/getline
	 * stoi: https://en.cppreference.com/cpp/string/basic_string/stol
 * <print>
	 * print: https://en.cppreference.com/cpp/io/print
	 * println: https://en.cppreference.com/cpp/io/println
 * exit: https://en.cppreference.com/cpp/utility/program/exit
*/

int main()
{
	// -method 1: ostream------------------------------------------
	std::cout << "Calculating average: enter numbers, "
		<< "or enter 'q' when finished.\n";

	int total = 0;
	int n = 0;
	while (true) {
		std::string s;
		int x;

		// because we can either expect the user to enter a number, or 'q', let's let
		// them enter a string, and check what they entered
		std::cout << ">>> ";
		std::getline(std::cin, s, '\n');

		// if an error happened in the console input, it's irrecoverable
		if (not std::cin.good()) {
			std::exit(1);
		}

		if (s == "q") {
			break;
		}

		try {
			// try and convert the string given into an integer with std::stoi
			std::size_t chars_converted;
			x = std::stoi(s, &chars_converted);
			if (chars_converted != s.length()) {
				throw std::invalid_argument("not an integer");
			}

			// if we go this far, the conversion succeeded so we have our
			// integer
			total += x;
			++n;
		}
		catch (const std::invalid_argument&) {
			std::cout << '"' << s << "\" is not an integer.\n";
		}
	}

	if (n == 0) {
		std::cout << "No numbers given.\n";
	}
	else {
		std::cout << "The average of all of your numbers is "
			<< (float)total / n << ".\n";
	}

	// print a horizontal rule between format methods
	std::cout << std::string(80, '-') << '\n';

	// -method 2: print & println----------------------------------
	// NOTE: we don't really have a good alternative for input;
	// istream is still used
	
	const int SIZE = 128;
	int even_numbers[SIZE];
	int count = 0;
	int sum = 0;
	
	std::println("\nFiltering even numbers given: enter numbers, "
			"or enter 'q' when finished.");

	while (count < SIZE) {
		std::string s;
		int x;

		std::cout << ">>> ";
		std::getline(std::cin, s, '\n');

		if (not std::cin.good()) {
			std::exit(1);
		}

		if (s == "q") {
			break;
		}

		try {
			std::size_t chars_converted;
			x = std::stoi(s, &chars_converted);
			if (chars_converted != s.length()) {
				throw std::invalid_argument("not an integer");
			}

			if (x % 2 == 0) {
				even_numbers[count++] = x;
				sum += x;
			}
		}
		catch (const std::invalid_argument&) {
			std::println("\"{}\" is not an integer.", s);
		}
	}

	if (count >= 1) {
		std::print("Numbers entered: {}", even_numbers[0]);

		for (int i = 1; i < count; ++i) {
			std::print(", {}", even_numbers[i]);
		}

		std::print("\n");
	}

	std::println("The sum of all the even numbers given is {}.", sum);


	return 0;
}
