#include <iostream>

using namespace std;

int main(void)
{
	double n, m, l, r, d, v;

	cin >> n >> m;
	l = n - m;
	r = n + m;
	d = 0;
	v = 7;

	while (d < l) {
		d += v;
		v *= 0.98;
	}
	if (d + v > r)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
