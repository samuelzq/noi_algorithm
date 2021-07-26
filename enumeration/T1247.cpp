#include <iostream>

using namespace std;

int main(void)
{
	int c, n;

	cin >> n;
	c = 0;

	for (int i = 10; i < 31; i++) {
		int d0, d1, d2;
		int d = i * i;
		d0 = d % 10;
		d1 = (d / 10) % 10;
		d2 = d / 100;

		if (d0 == d1 || d0 == d2 || d1 == d2)
			c++;
		if (c == n) {
			cout << d;
			break;
		}
	}
	return 0;
}
