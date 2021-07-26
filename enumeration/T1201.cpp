#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	int x = 2;

	cin >> a >> b >> c;

	while (1) {
		if (a % x == b % x && b % x == c % x) {
			cout << x;
			return 0;
		}
		x++;
	}
}
