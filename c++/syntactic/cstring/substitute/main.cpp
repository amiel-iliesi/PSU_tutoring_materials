#include "substitute.h"
#include <iostream>

using namespace std;

const unsigned STRBUF_SIZE = 1024;

int main()
{
	char sentence[STRBUF_SIZE];
	char match[STRBUF_SIZE];
	char replace[STRBUF_SIZE];

	cout << "enter a phrase:\n>>> ";
	cin.getline(sentence, STRBUF_SIZE);

	cout << "part to replace:\n>>> ";
	cin.getline(match, STRBUF_SIZE);

	cout << "replace with:\n>>> ";
	cin.getline(replace, STRBUF_SIZE);

	substitute(sentence, match, replace);

	cout << "your new sentence:\n\"" << sentence << "\"" << endl;

	return 0;
}
