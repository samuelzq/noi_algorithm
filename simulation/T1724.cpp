#include <iostream>
#include <algorithm>

using namespace std;

int s[1003];

int main(void)
{
	int n, t, p, r, m, idx, l;

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	p = 0;
	r = 0;
	l = -1;
	for (int i = 0; i < t; i++) {
		m = 0;
		for (int j = 0; j < n; j++) {
			if (m < s[j]) {
				idx = j;
				m = s[j];
			}
		}
		l = idx;
		s[l] = 0;
		cout << l + 1 << '\n';

		r = m % (n - 1);
		p = m / (n - 1);
		for (int j = 0; j < n && r; j++) {
			if (j == l)
				continue;
			s[j] += 1;
			r--;
		}
		for (int j = 0; j < n; j++) {
			if (j == l)
				continue;
			s[j] += p;
		}
	}
	return 0;
}
