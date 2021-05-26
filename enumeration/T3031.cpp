#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long n, t, x, y;

	cin >> n;
	t = sqrt(n) + 1;

	for (x = t; x > 0; x --) {
		if (n % x == 0) {
			y = n / x;

			if (y > x)
				cout << y << ' ' << x;
			else
				cout << x << ' ' << y;
			return 0;
		}
	}
}
