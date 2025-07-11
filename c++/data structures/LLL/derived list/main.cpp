#include <iostream>
#include "list.h"

using namespace std;

int main() {
	NumberNode * numbers = nullptr;
	TextNode * chars = nullptr;

	for (float f: {1.23, 4.56, 3.14, 5.0}) {
		numbers = new NumberNode(f, numbers);
	}

	for (char c: {'a','c','d','f','h'}) {
		chars = new TextNode(c, chars);
	}

	while (numbers) {
		numbers->square();
		numbers = numbers->next;
	}

	while (chars) {
		chars->repeat();
		chars = chars->next;
	}

	return 0;
}
