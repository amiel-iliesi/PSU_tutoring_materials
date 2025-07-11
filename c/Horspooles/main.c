#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// NOTE: usage: this program expects the following lines supplied via stdin:
/*
[LINE 0: main string to be searched]
[LINE 1: search string]
*/

int main()
{
	char * main_string = NULL;
	char * search_string = NULL;

	// 1. get both strings; sizes won't be used beyond error handling--create them in local scope
	{
		size_t main_size = 0;
		getline(&main_string, &main_size, stdin);
		if (main_size == -1) {
			perror("failed to read line 0");
			return EXIT_FAILURE;
		}
	}
		{
		size_t search_size = 0;
		getline(&search_string, &search_size, stdin);
		if (search_size == -1) {
			perror("failed to read line 1");
			return EXIT_FAILURE;
		}
	}

	size_t main_len = strlen(main_string);
	if (!main_string || main_len == 0) {
		fprintf(stderr, "main string cannot be empty\n");
		return EXIT_FAILURE;
	}
	size_t search_len = strlen(search_string);
	if (!search_string || search_len == 0) {
		fprintf(stderr, "search string cannot be empty\n");
		return EXIT_FAILURE;
	}

	// 2. remove newline at the end of strings; getline stores them
	if (main_string[main_len-1] == '\n') { // it should be at the end, but it doesn't hurt to check
		main_string[--main_len] = '\0';
	}
	if (search_string[search_len-1] == '\n') {
		search_string[--search_len] = '\0';
	}

	// 3. initialize jump table
	// HACK: size 8 implicitly limits search string to size 255; change type if that limit is too small
	uint_fast8_t jump_table[256]; 
	for (int i = 0; i < 256; ++i) {
		jump_table[i] = search_len;
	}

	// 4. calculate jump table for matching chars
	for (size_t i = 0; i < search_len; ++i) {
		jump_table[(int)search_string[i]] = (search_len - 1) - i;
	}

	// 5. find first matching index (if any)
	ssize_t found_index = -1;
	unsigned comparisons = 0;
	// start at search_len - 1 to right-align the search region
	{
	ssize_t i = search_len - 1;
		while(i < main_len) {
			bool matches = true;
			ssize_t main_offset = i - (search_len - 1); // undo i's right-align offset for string comparison
			
			for (int j = 0; j < search_len && matches; ++j) {
				++comparisons;
				if (search_string[j] != main_string[main_offset + j]) {
					matches = false;
				}
			}

			if (matches) {
				found_index = i - (search_len - 1);
				break;
			}
			else {
				i += jump_table[(int)main_string[i]];
			}
		}
	}

	// 6. output results
	if (found_index == -1) {
		fprintf(stderr, "no match found\n");
		return EXIT_FAILURE;
	}
	else {
		printf("index: %li\nnumber of comparisons: %u\n", found_index, comparisons);
	}

	// 7. getline allocates space, so we need to free before we leave. see `man getline`
	free(main_string);
	free(search_string);

	return EXIT_SUCCESS;
}
