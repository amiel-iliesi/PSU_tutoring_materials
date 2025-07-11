#include <stdio.h>

int main()
{
	// 1. determine base
	int base;
	scanf("%d", &base);

	// 2. read value in corresponding format to base
	int value;

	switch (base) {
		case 8:
			printf("octal input\n");
			scanf("%o", &value);
			break;
		case 10:
			printf("decimal input\n");
			scanf("%d", &value);
			break;
		case 16:
			printf("hexadecimal input\n");
			scanf("%x", &value);
			break;
		default:
			printf("%d is not a base we are converting to.\n", base);
	}

	// 3. cast the value to a char
	char c = value;
	
	// 4. show our results
	printf("we read the character %c as %d from base %d\n", c, value, base);

	return 0;
}
