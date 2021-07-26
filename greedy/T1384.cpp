#include <iostream>
#include <algorithm>

using namespace std;

int p[303] = {0, };

int main(void)
{
	int s, w, n, ans, sum;

	cin >> s;

	while (s--) {
		int l, r;
		cin >> w >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		ans = 0;
		sort(p, p + n);
		sum = p[n - 1];
		l = 0;
		r = n - 1;
		while (l <= r) {
			if (p[l] + p[r] <= w) {
				ans++;
				l++;
				r--;
			} else {
				ans++;
				r--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
