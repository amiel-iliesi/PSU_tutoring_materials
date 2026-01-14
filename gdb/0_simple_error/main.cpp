#include <iostream>

using namespace std;

void math_add(int& x, int& y);
void math_div(int& x, int& y);

int main()
{
	int a = 5;
	int b = 7;

	cout << "Let's do some math on `a` and `b`!\n";
	cout << "\na=" << a << "\nb=" << b << '\n';

	math_add(a, b);
	math_div(a, b);

	cout << "\na=" << a << "\nb=" << b << '\n';

	return 0;
}

void math_add(int& x, int& y)
{
	x += 3;
	y -= 7;
}

void math_div(int& x, int& y)
{
	y /= 2;
	x /= y;
}

