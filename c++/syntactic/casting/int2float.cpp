#include <iostream>

using namespace std;

int main()
{
	int sum = 503; // GOOD: 50.3, GET: 50.0

	//(float) ((float) 3 / (int) 4) // f/i? -> f/f

	float division = (float) sum / 10; // we SHOULD see: 0.75

	cout << sum << '/' << 10 << " = " << division << endl;

	return 0;
}
