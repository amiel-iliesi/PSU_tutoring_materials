#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int BASE = 10;
	char input[100];
	fgets(input, 100, stdin);

	char * endptr;
	int input_value = strtol(input, &endptr, BASE);

	if (!endptr || endptr == input) {
		fprintf(stderr, "invalid integer input: %s\n", input);
		return 1;
	}

	// if user said 1: print "hi", 2 print "kaboom" and "wow", 3: print "wow",
	// if they input something other than those, say "WRONG! bad input"

	switch (input_value) {
		case 1:
			printf("hi\n");
			break;
		case 2:
			printf("kaboom\n");
			// NOTE: no break, fallthrough will occur
		case 3:
			printf("wow\n");
			break;
		default:
			printf("WRONG! bad input\n");
			return 1;
	}

	return 0;
}
