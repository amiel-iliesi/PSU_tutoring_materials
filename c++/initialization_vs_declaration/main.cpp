#include <iostream>

using namespace std;

struct grouped_data
{
	int x;
	char c;
};

int main()
{
	grouped_data D;


//	NOTE: uncomment the following and observe the effects below
//	D->x = 15;
//	D->c = 'a';
	
	cout << D->x << ',' << D->c << endl;

	return 0;
}
