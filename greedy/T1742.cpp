#include <iostream>

using namespace std;

int a[1000006] = {0, };

int main(void)
{
	int n, m, ans, l, r, p;

	cin >> n >> m;

	l = 1000000;
	r = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t] = 1;
		if (r < t)
			r = t;
		if (l > t)
			l = t;
	}
	ans = 0;
	p = l;
	for (int i = l + 1; i < r; i++) {
		if (a[i]) {
			for (int j = i + 1; j <= r; j++) {
				if (a[j]) {
					if (j - p <= m)
						ans++;
					else
						p = i;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
