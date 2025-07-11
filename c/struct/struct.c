#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct QuadStatePair {
	uint8_t nums[2]; //could also be uint16_t if you wanted
	uint8_t states;
};

#define FIRST 0
#define SECOND 1

void print_num(struct QuadStatePair, uint8_t, uint8_t);

int main() {
	uint8_t first_quad = 0xA5; //1010 0101
	uint8_t first_state = 0xF; //0000 1111: select all
	uint8_t second_quad = 0xF0; //1111 0000
	uint8_t second_state = 0x50; //0101 0000: select every other

	struct QuadStatePair bundle;
	bundle.nums[FIRST] = first_quad;
	bundle.nums[SECOND] = second_quad;
	bundle.states |= first_state;
	bundle.states |= second_state;


	print_num(bundle, SECOND, 3);

	return EXIT_SUCCESS;
}

void print_num(struct QuadStatePair nums, uint8_t which_num, uint8_t num_index) {
	uint8_t shift_amt = 2 * num_index;
	uint8_t twobit = (nums.nums[which_num] & (0x3 << shift_amt)) >> shift_amt;

	printf("%c%c: %s\n", ((twobit & 0x2) ? '1' : '0'), ((twobit & 0x1) ? '1' : '0'),
						 ((nums.states & (0x1 << (4 * which_num + num_index)) ? "true" : "false")));
}
