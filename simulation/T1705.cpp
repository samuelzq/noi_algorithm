#include <iostream>

using namespace std;

int main(void)
{
	long long a, b, c, x, y, z, t;

	cin >> a >> b >> c >> x >> y >> z;

	if (a > c) {
		cout << a + b / z;
		return 0;
	}

	t = (c - a) * x;
	if (t >= b)
		cout << a + b / x;
	else {
		long long ans = c;
		t = b - t;
		if (t < y)
			cout << c;
		else
			cout << c + (t - y) / z;
	}
	return 0;
}
