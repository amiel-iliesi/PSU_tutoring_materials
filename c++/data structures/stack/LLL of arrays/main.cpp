#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack sentences;

	cout << "pushing:\n";
	for (const char * sentence: {
			"Hello, world!",
			"This is a long sentence with many words. Neat!",
			"Ciao.",
			"Another one.",
			"Cool."})
	{
		cout << "\t> \"" << sentence << "\"\n";
		sentences.push(sentence);
	}

	cout << "popping:\n";
	char retrieved[1024];
	while (not sentences.is_empty()) {
		sentences.peek(retrieved);
		cout << "\t> \"" << retrieved << "\"\n";
		sentences.pop();
	}

	return 0;
}
