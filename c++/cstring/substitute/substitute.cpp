#include "substitute.h"
#include <cstring>

// NOTE: this file does not account for what happens when you go beyond this
// static size!

const unsigned STRBUF_SIZE = 1024; 

// substitutes all matches of `match` in `s` with `replace`
void substitute(char * s, const char * match, const char * replace)
{
	// XXX: This is naive, we should use Horspool's algorithm
	char temp[STRBUF_SIZE];
	unsigned temp_top = 0;

	for (int si = 0; si < strlen(s); ++si) {
		bool matches = true;

		for (int mi = 0; mi < strlen(match); ++mi) {
			if (s[si+mi] != match[mi]) {
				matches = false;
				break;
			}
		}

		if (matches) {
			for (int ri = 0; ri < strlen(replace); ++ri) {
				temp[temp_top++] = replace[ri];
			}
			si += strlen(match)-1; //-1: compensate for ++si on loop
		}
		else {
			temp[temp_top++] = s[si];
		}
	}

	temp[temp_top++] = '\0';

	strcpy(s, temp);
}
