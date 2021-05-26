#include <iostream>

using namespace std;

int main(void)
{
	long long x, y, q, p, ans = 0;

	cin >> x >> y;
	for (q = x; q <= y; q += x) {
		int t, w;
		if (x * y % q != 0)
			continue;
		p = x * y / q;
		if (p % x != 0)
			continue;
		if (q > p) {
			t = q;
			w = p;
		} else {
			t = p;
			w = q;
		}
		while (w) {
			int n = t % w;
			t = w;
			w = n;
		}
		if (t == x) {
			//cout << q << ' ' << p << '\n';
			ans++;
		}
	}
	cout << ans;
	return 0;
}
