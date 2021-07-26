#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d;

	if (b > d) {
		c--;
		d += 60;
	}
	cout << c - a << ' ' << d - b;
	return 0;
}
