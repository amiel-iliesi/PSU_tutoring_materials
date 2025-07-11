#include "stdio.h"

int main(void)
{
	double x = 3.0; //some weird hex val
	unsigned long x_unsigned = (unsigned long) x; //0b0..0011
	unsigned long x_unsigned_RC = * (unsigned long *) &x; //keep the same bits from float x

	printf("%f\n%lu\n0x%lx\n", x, x_unsigned, x_unsigned_RC);
	
	return 0;
}
