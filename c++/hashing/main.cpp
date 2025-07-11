#include "hash.h"
#include <iostream>

#define CALL_OUTPUT(F, K) { std::cout << #F << '(' << #K << ") = " << F(K) << std::endl; }

int main()
{
	CALL_OUTPUT(hash_cstring, "abcdefg");
	CALL_OUTPUT(hash, std::string("abcdefg"));

	return 0;
}
