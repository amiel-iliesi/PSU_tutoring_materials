#include "list.h"
#include <random>
#include <print>
#include <string>
#include <format>

using namespace std;

string header(const string& header_text);

int main()
{
	List list;

	random_device rd;
	default_random_engine gen(rd());

	for (int i = 8 + gen() % 8; i >= 0; --i) {
		list.push(gen() % 10);
	}
	println("{}", header("initial list"));
	list.display();

	println(""); //section padding
	// -custom function calls here---------------------------------
	println("{}", header("custom functions"));

	println("list.recursive_display_wrapper():");
	list.recursive_display_wrapper();
	// ------------------------------------------------------------

	return 0;
}

string header(const string& header_text)
{
	int width = 80 - (int)header_text.length();

	if (width <= 0) {
		return header_text;
	}

	return format("-{}{}", header_text, string(width-1, '-'));
}
