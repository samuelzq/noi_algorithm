#include <iostream>
#include <cmath>

using namespace std;

#if 0
int main(void)
{
	double p;
	long long y, t, l, r, m, s;

	cin >> p >> y >> t;

	p = 1 + p / 100;
	l = 1;
	r = t;
	while (l <= t) {
		m = l + (r - l) / 2;
		s = 0;
		for (int i = 0; i < y; i++) {
			s = (s + m) * p;
			if (s > t)
				break;
		}
		if (s == t)
			break;
		else if (s > t)
			r = m - 1;
		else if (s < t)
			l = m + 1;
	}
	cout << m;
	return 0;
}
#else
int main(void)
{
	double p;
	double y, t;
	cin >> p >> y >> t;
	p = 1 + p / 100.0;

	double ans = 0;
	for (int i = 0; i < y; i++) {
		ans += p;
		p *= p;
	}
	ans = t/ans;
	cout << (long long)ceil(ans) << endl;

	return 0;
}
#endif
