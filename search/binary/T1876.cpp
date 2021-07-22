#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long n, m, l, r;

	cin >> n;

	l = 1;
	r = 2 * 1e9;
	while (l <= r) {
		m = l + (r - l) / 2;

		if (m * log10(m) + 1 > n)
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l;
	return 0;
}
